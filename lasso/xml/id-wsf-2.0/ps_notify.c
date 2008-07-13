/* $Id: ps_notify.c,v 1.0 2005/10/14 15:17:55 fpeters Exp $ 
 *
 * Lasso - A free implementation of the Liberty Alliance specifications.
 *
 * Copyright (C) 2004-2007 Entr'ouvert
 * http://lasso.entrouvert.org
 * 
 * Authors: See AUTHORS file in top-level directory.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ps_notify.h"

/**
 * SECTION:ps_notify
 * @short_description: &lt;ps:Notify&gt;
 *
 * <figure><title>Schema fragment for ps:Notify</title>
 * <programlisting><![CDATA[
 *
 * <xs:complexType name="NotifyType">
 *   <xs:complexContent>
 *     <xs:extension base="RequestAbstractType">
 *       <xs:sequence>
 *         <xs:element ref="Notification" minOccurs="0" maxOccurs="unbounded"/>
 *       </xs:sequence>
 *       <xs:attributeGroup ref="subs:NotifyAttributeGroup"/>
 *     </xs:extension>
 *   </xs:complexContent>
 * </xs:complexType>
 * ]]></programlisting>
 * </figure>
 */

/*****************************************************************************/
/* private methods                                                           */
/*****************************************************************************/


static struct XmlSnippet schema_snippets[] = {
	{ "Notification", SNIPPET_LIST_NODES,
		G_STRUCT_OFFSET(LassoIdWsf2PsNotify, Notification) },
	{ "timeStamp", SNIPPET_ATTRIBUTE | SNIPPET_OPTIONAL,
		G_STRUCT_OFFSET(LassoIdWsf2PsNotify, timeStamp) },
	{NULL, 0, 0}
};

static LassoNodeClass *parent_class = NULL;


/*****************************************************************************/
/* instance and class init functions                                         */
/*****************************************************************************/

static void
instance_init(LassoIdWsf2PsNotify *node)
{
	node->Notification = NULL;
	node->timeStamp = NULL;
}

static void
class_init(LassoIdWsf2PsNotifyClass *klass)
{
	LassoNodeClass *nclass = LASSO_NODE_CLASS(klass);

	parent_class = g_type_class_peek_parent(klass);
	nclass->node_data = g_new0(LassoNodeClassData, 1);
	lasso_node_class_set_nodename(nclass, "Notify");
	lasso_node_class_set_ns(nclass, LASSO_IDWSF2_PS_HREF, LASSO_IDWSF2_PS_PREFIX);
	lasso_node_class_add_snippets(nclass, schema_snippets);
}

GType
lasso_idwsf2_ps_notify_get_type()
{
	static GType this_type = 0;

	if (!this_type) {
		static const GTypeInfo this_info = {
			sizeof (LassoIdWsf2PsNotifyClass),
			NULL,
			NULL,
			(GClassInitFunc) class_init,
			NULL,
			NULL,
			sizeof(LassoIdWsf2PsNotify),
			0,
			(GInstanceInitFunc) instance_init,
		};

		this_type = g_type_register_static(LASSO_TYPE_IDWSF2_PS_REQUEST_ABSTRACT,
				"LassoIdWsf2PsNotify", &this_info, 0);
	}
	return this_type;
}

/**
 * lasso_idwsf2_ps_notify_new:
 *
 * Creates a new #LassoIdWsf2PsNotify object.
 *
 * Return value: a newly created #LassoIdWsf2PsNotify object
 **/
LassoIdWsf2PsNotify*
lasso_idwsf2_ps_notify_new()
{
	return g_object_new(LASSO_TYPE_IDWSF2_PS_NOTIFY, NULL);
}
