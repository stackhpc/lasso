/*
 * Lasso library C unit tests
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

#include <stdlib.h>
#include <string.h>

#include <check.h>

#include <lasso/lasso.h>


START_TEST(test01_server_load_dump_empty_string)
{
	LassoServer *serverContext;
	serverContext = lasso_server_new_from_dump("");
	fail_unless(serverContext == NULL,
			"serverContext was created from an empty string dump");
}
END_TEST

START_TEST(test02_server_load_dump_random_string)
{
	LassoServer *serverContext;
	serverContext = lasso_server_new_from_dump("foo");
	fail_unless(serverContext == NULL,
			"serverContext was created from a fake dump");
}
END_TEST

START_TEST(test03_server_load_dump_random_xml)
{
	LassoServer *serverContext;
	serverContext = lasso_server_new_from_dump("<?xml version=\"1.0\"?><foo/>");
	fail_unless(serverContext == NULL,
			"serverContext was created from fake (but valid XML) dump");
}
END_TEST


START_TEST(test04_identity_load_dump_null)
{
	LassoIdentity *identity;

	identity = lasso_identity_new_from_dump(NULL);
	fail_unless(identity == NULL, "identity was created from NULL dump");
}
END_TEST

START_TEST(test05_identity_load_dump_empty)
{
	LassoIdentity *identity;

	identity = lasso_identity_new_from_dump("");
	fail_unless(identity == NULL, "identity was created from empty dump");
}
END_TEST


Suite*
basic_suite()
{
	Suite *s = suite_create("Basic");
	TCase *tc_server_load_dump_empty_string = tcase_create("Create server from empty string");
	TCase *tc_server_load_dump_random_string = tcase_create("Create server from random string");
	TCase *tc_server_load_dump_random_xml = tcase_create("Create server from random XML");
	TCase *tc_identity_load_dump_null = tcase_create("Create identity from NULL");
	TCase *tc_identity_load_dump_empty = tcase_create("Create identity from empty string");
	suite_add_tcase(s, tc_server_load_dump_empty_string);
	suite_add_tcase(s, tc_server_load_dump_random_string);
	suite_add_tcase(s, tc_server_load_dump_random_xml);
	suite_add_tcase(s, tc_identity_load_dump_null);
	suite_add_tcase(s, tc_identity_load_dump_empty);
	tcase_add_test(tc_server_load_dump_empty_string, test01_server_load_dump_empty_string);
	tcase_add_test(tc_server_load_dump_random_string, test02_server_load_dump_random_string);
	tcase_add_test(tc_server_load_dump_random_xml, test03_server_load_dump_random_xml);
	tcase_add_test(tc_identity_load_dump_null, test04_identity_load_dump_null);
	tcase_add_test(tc_identity_load_dump_empty, test05_identity_load_dump_empty);
	return s;
}

