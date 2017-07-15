#!/usr/bin/env make
## -*- coding: utf-8; mode: make; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#
# Copyright (C) 2017 Arqadium. All rights reserved.
#
# This Source Code Form is subject to the terms of the Mozilla Public License,
# version 2.0. If a copy of the MPL was not distributed with this file, you
# can obtain one at <http://mozilla.org/MPL/2.0/>.
#

export SLNDIR := $(PWD)
export TARGET := debug
#export TARGET := release

.PHONY: all lint engine lz4 json clean distclean

all: lz4 json engine

lint:
	@make -C src/lz4 lint
	@make -C src/json lint
	@make -C src/engine lint

engine:
	@make -C src/engine all

lz4:
	@make -C src/lz4 all

json:
	@make -C src/json all

clean:
	@make -C src/lz4 clean
	@make -C src/json clean
	@make -C src/engine clean

distclean:
	@make -C src/lz4 distclean
	@make -C src/json distclean
	@make -C src/engine distclean
