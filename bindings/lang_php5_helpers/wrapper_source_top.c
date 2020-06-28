#include <php.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION
#include <lasso/lasso.h>
#include "php_lasso.h"
#include "../ghashtable.h"

/* utility functions */
static void free_glist(GList **list, GFunc free_function);

/* Define the Lasso PHP module */

int le_lasso_server;

ZEND_GET_MODULE(lasso)

/* Wrapper around GObject to get the dynamic typename */

typedef struct {
	GObject *obj;
	char *typename;
} PhpGObjectPtr;

/** FIXME: implement caching of objects inside GObjects using a GQuark */
static PhpGObjectPtr*
PhpGObjectPtr_New(GObject *obj)
{
	PhpGObjectPtr *self;

	if (obj == NULL) {
		return NULL;
	}

	self = (PhpGObjectPtr *)malloc(sizeof(PhpGObjectPtr));
	self->obj = g_object_ref(obj);
	self->typename = strdup(G_OBJECT_TYPE_NAME(obj));
        //printf("Allocating container %p for object %p of type %s with refcnt %i\n", self, obj, self->typename, obj->ref_count);

	return self;
}
PHP_FUNCTION(lasso_init)
{
	RETURN_NULL();
}
PHP_FUNCTION(lasso_shutdown)
{
	RETURN_NULL();
}
PHP_FUNCTION(lasso_get_object_typename)
{
	PhpGObjectPtr *self;
	zval *zval_self;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zval_self) == FAILURE) {
		RETURN_FALSE;
	}

	ZEND_FETCH_RESOURCE(self, PhpGObjectPtr *, &zval_self, -1, PHP_LASSO_SERVER_RES_NAME, le_lasso_server);
	RETURN_STRING(self->typename, 1);
}

/* Generic destructor for PHP GObject  */
static void php_gobject_generic_destructor(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    PhpGObjectPtr* gobject = (PhpGObjectPtr*)rsrc->ptr;

    if (gobject) {
        if (gobject->obj) {
            //printf("Deallocating container %p\n", gobject);
            //printf("Deallocating %p that has %u refcounts\n", gobject->obj, gobject->obj->ref_count);
            g_object_unref(G_OBJECT(gobject->obj));
            //printf("now %u refcounts\n", gobject->obj->ref_count);
        }
        if (gobject->typename) {
            free(gobject->typename);
        }
        free(gobject);
    }
}

/* List handling */
static void 
free_glist(GList **list, GFunc free_function) {
    g_return_if_fail(list);
    if (*list) {
        if (free_function) {
            g_list_foreach(*list, free_function, NULL);
        }
        g_list_free(*list);
    }
    *list = NULL;
}
/* Conversion functions */

static char*
get_string_from_xml_node(xmlNode *xmlnode)
{
	xmlOutputBufferPtr buf;
	char *xmlString;

	if (xmlnode == NULL) {
		return NULL;
	}

	buf = xmlAllocOutputBuffer(NULL);
	if (buf == NULL) {
		xmlString = NULL;
	} else {
		xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 1, NULL);
		xmlOutputBufferFlush(buf);
		if (buf->conv == NULL) {
			xmlString = estrdup((char*)buf->buffer->content);
		} else {
			xmlString = estrdup((char*)buf->conv->content);
		}
		xmlOutputBufferClose(buf);
	}

	return xmlString;
}

static xmlNode*
get_xml_node_from_string(char *string)
{
	xmlDoc *doc;
	xmlNode *node;

	doc = xmlReadDoc((xmlChar*)string, NULL, NULL, XML_PARSE_NONET);
	node = xmlDocGetRootElement(doc);
	if (node != NULL) {
		node = xmlCopyNode(node, 1);
	}
	xmlFreeDoc(doc);

	return node;
}

static GList*
get_list_from_array_of_strings(zval* array)
{
	HashTable* hashtable;
	HashPosition pointer;
	int size;
	zval** data;
	zval temp;
	GList* result = NULL;

	hashtable = Z_ARRVAL_P(array);
	size = zend_hash_num_elements(hashtable);
	for (zend_hash_internal_pointer_reset_ex(hashtable, &pointer);
			zend_hash_get_current_data_ex(hashtable, (void**) &data, &pointer) == SUCCESS;
			zend_hash_move_forward_ex(hashtable, &pointer)) {
		temp = **data;
		zval_copy_ctor(&temp);
		convert_to_string(&temp);
		result = g_list_append(result, g_strndup(Z_STRVAL(temp), Z_STRLEN(temp)));
		zval_dtor(&temp);
	}
	return result;
}

static void
set_array_from_list_of_strings(GList* list, zval **array) {
	GList* item;

	array_init(*array);
	for (item = g_list_first(list); item != NULL; item = g_list_next(item)) {
		if (item->data != NULL) {
			add_next_index_string(*array, item->data, 1);
		} else {
			add_next_index_null(*array);
		}
	}
}

static GList*
get_list_from_array_of_xmlnodes(zval* array)
{
	HashTable* hashtable;
	HashPosition pointer;
	int size;
	zval** data;
	zval temp;
	GList* result = NULL;

	hashtable = Z_ARRVAL_P(array);
	size = zend_hash_num_elements(hashtable);
	for (zend_hash_internal_pointer_reset_ex(hashtable, &pointer);
			zend_hash_get_current_data_ex(hashtable, (void**) &data, &pointer) == SUCCESS;
			zend_hash_move_forward_ex(hashtable, &pointer)) {
		temp = **data;
		zval_copy_ctor(&temp);
		convert_to_string(&temp);
		result = g_list_append(result, get_xml_node_from_string(Z_STRVAL(temp)));
		zval_dtor(&temp);
	}
	return result;
}

static void
set_array_from_list_of_xmlnodes(GList* list, zval **array) {
	GList* item;

	array_init(*array);
	for (item = g_list_first(list); item != NULL; item = g_list_next(item)) {
		if (item->data != NULL) {
			add_next_index_string(*array, get_string_from_xml_node(item->data), 0);
		} else {
			add_next_index_null(*array);
		}
	}
}

static GList*
get_list_from_array_of_objects(zval *array)
{
	HashTable *hashtable;
	HashPosition pointer;
	int size;
	zval **data;
	PhpGObjectPtr *cvt_temp;
	GList *result = NULL;

	hashtable = Z_ARRVAL_P(array);
	size = zend_hash_num_elements(hashtable);
	for (zend_hash_internal_pointer_reset_ex(hashtable, &pointer);
			zend_hash_get_current_data_ex(hashtable, (void**) &data, &pointer) == SUCCESS;
			zend_hash_move_forward_ex(hashtable, &pointer)) {
		cvt_temp = (PhpGObjectPtr*) zend_fetch_resource(data TSRMLS_CC, -1, PHP_LASSO_SERVER_RES_NAME, NULL, 1, le_lasso_server);
		if (cvt_temp != NULL) {
                        g_object_ref(cvt_temp->obj);
			result = g_list_append(result, cvt_temp->obj);
		} else {
			result = g_list_append(result, NULL);
		}
	}
	return result;
}

static void
set_array_from_list_of_objects(GList *list, zval **array)
{
	GList *item = NULL;
	zval *zval_item = NULL;

	array_init(*array);
	for (item = g_list_first(list); item != NULL; item = g_list_next(item)) {
		if (item->data != NULL) {
                        MAKE_STD_ZVAL(zval_item);
			ZEND_REGISTER_RESOURCE(zval_item, PhpGObjectPtr_New(item->data), le_lasso_server);
			add_next_index_zval(*array, zval_item);
		} else {
			add_next_index_null(*array);
		}
	}
}

/* FIXME: This function doesn't work yet */
static GHashTable*
get_hashtable_from_array_of_objects(zval *array)
{
	HashTable *hashtable = NULL;
	HashPosition pointer;
	int size;
	char *key = NULL;
	unsigned int key_len;
	unsigned long index;
	zval **data = NULL;
	PhpGObjectPtr *cvt_temp = NULL;
	GHashTable *result = NULL;

	result = g_hash_table_new(g_str_hash, g_str_equal);
	hashtable = Z_ARRVAL_P(array);
	size = zend_hash_num_elements(hashtable);
	for (zend_hash_internal_pointer_reset_ex(hashtable, &pointer);
			zend_hash_get_current_data_ex(hashtable, (void**) &data, &pointer) == SUCCESS;
			zend_hash_move_forward_ex(hashtable, &pointer)) {
		cvt_temp = (PhpGObjectPtr*) zend_fetch_resource(data TSRMLS_CC, -1, PHP_LASSO_SERVER_RES_NAME, NULL, 1, le_lasso_server);
		if (zend_hash_get_current_key_ex(hashtable, &key, &key_len, &index, 0, &pointer) == HASH_KEY_IS_STRING) {
			if (cvt_temp != NULL) {
				g_hash_table_insert(result, key, g_object_ref(cvt_temp->obj));
			} else {
				g_hash_table_insert(result, key, NULL);
			}
		} else {
			if (cvt_temp != NULL) {
				g_hash_table_insert(result, (gpointer)index, g_object_ref(cvt_temp->obj)); 
			} else {
				g_hash_table_insert(result, (gpointer)index, NULL); 
			}
		}
	}
	return result;
}

static void
set_array_from_hashtable_of_objects(GHashTable *hashtable, zval **array)
{
	GList *keys = NULL;
	GObject *item = NULL;
	zval *zval_item = NULL;

	array_init(*array);
	for (keys = g_hash_table_get_keys(hashtable); keys; keys = g_list_next(keys)) {
		item = g_hash_table_lookup(hashtable, keys->data);
		if (item) {
			MAKE_STD_ZVAL(zval_item);
			ZEND_REGISTER_RESOURCE(zval_item, PhpGObjectPtr_New(item), le_lasso_server);
			add_assoc_zval(*array, (char*)keys->data, zval_item);
		} else {
			add_assoc_null(*array, (char*)keys->data);
		}
	}
	g_list_free(keys);
}

