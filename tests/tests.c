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
#include <lasso_config.h>

#include <check.h>
#include <lasso/lasso.h>

extern Suite* basic_suite();
extern Suite* login_suite();
extern Suite* random_suite();
extern Suite* metadata_suite();

typedef Suite* (*SuiteFunction) ();

SuiteFunction suites[] = {
	basic_suite,
	login_suite,
	random_suite,
	metadata_suite,
	NULL
};

int
main(int argc, char *argv[])
{
	int rc;
	SRunner *sr;
	int i;
	int dont_fork = 0;

	for (i=1; i<argc; i++) {
		if (strcmp(argv[i], "--dontfork") == 0) {
			dont_fork = 1;
		}
	}

	lasso_init();
	
	sr = srunner_create(suites[0]());

	i = 1;
	while (suites[i]) {
		srunner_add_suite(sr, suites[i]());
		i++;
	}

	if (dont_fork) {
		srunner_set_fork_status(sr, CK_NOFORK);
	}
#ifdef CHECK_IS_XML
	srunner_set_xml(sr, "result.xml");
#endif
	srunner_run_all (sr, CK_VERBOSE);
	rc = srunner_ntests_failed(sr);
	
	srunner_free(sr);
	/*suite_free(s);  */
	/* no longer available in check 0.9.0; it will leak a
	 * bit with previous versions */

	return (rc == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

