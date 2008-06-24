# Lasso - A free implementation of the Liberty Alliance specifications.
# 
# Copyright (C) 2004-2007 Entr'ouvert
# http://lasso.entrouvert.org
#
# Authors: See AUTHORS file in top-level directory.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

import os

from lang_php5_helpers.wrapper_source import WrapperSource
from lang_php5_helpers.wrapper_header import WrapperHeader
from lang_php5_helpers.php_code import PhpCode

class Php5Binding:
    def __init__(self, binding_data):
        self.binding_data = binding_data

    def generate(self):
        fd = open('_lasso.c', 'w')
        wrapper_source = WrapperSource(self.binding_data, fd)
        wrapper_source.generate()
        fd.close()

        fd = open('php_lasso.h', 'w')
        WrapperHeader(self.binding_data, fd, wrapper_source.functions_list).generate()
        fd.close()

        fd = open('lasso.php', 'w')
        PhpCode(self.binding_data, fd).generate()
        fd.close()

