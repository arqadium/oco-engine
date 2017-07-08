#!/usr/bin/env make
## -*- coding: utf-8; mode: make; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#
# Copyright (C) 2017 Trinity Software, LLC. All rights reserved.
#
# This document contains proprietary information of TRINITY SOFTWARE and/or its
# licenced developers and are protected by national and international copyright
# laws. They may not be disclosed to third parties or copied or duplicated in
# any form, in whole or in part, without the prior written consent of
# Trinity Software, LLC.
#

export SLNDIR := $(PWD)
export TARGET := debug
#export TARGET := release

.PHONY: all lint engine lz4 clean distclean

all: lz4 engine

lint:
	@make -C src/lz4 lint
	@make -C src/engine lint

engine:
	@make -C src/engine all

lz4:
	@make -C src/lz4 all

clean:
	@make -C src/lz4 clean
	@make -C src/engine clean

distclean:
	@make -C src/lz4 distclean
	@make -C src/engine distclean
