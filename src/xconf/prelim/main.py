#!/usr/bin/env python3
# -*- coding: utf-8; mode: python; indent-tabs-mode: nil; tab-width: 4 -*-
#
# Copyright (C) 2017 Arqadium. All rights reserved.
#
# This Source Code Form is subject to the terms of the Mozilla Public License,
# version 2.0. If a copy of the MPL was not distributed with this file, you
# can obtain one at <http://mozilla.org/MPL/2.0/>.
#

def main(args):
    print('Good morning Vietnam!')
    return 0

if __name__ == '__main__':
    from sys import argv, exit
    exit(main(argv))
