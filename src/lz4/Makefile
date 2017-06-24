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

.SILENT

ifndef $(SLNDIR)
$(error This Makefile cannot be called directly.)
endif

PROJECT := lz4
OUTNAME := lib$(PROJECT).so

PRJDIR := $(SLNDIR)/src/$(PROJECT)

PLATFORM := $(shell uname -s)
TARGET   := debug
#TARGET   := release

ifeq ($(strip $(PLATFORM)),Linux)
PLTFLAGS := -DLINUX=1
else ($(strip $(PLATFORM)),Darwin)
PLTFLAGS := -DDARWIN=1
else
$(error Unsupported platform.)
endif

ifeq ($(strip $(TARGET)),debug)
TGTFLAGS := -UNDEBUG
else ($(strip $(TARGET)),release)
TGTFLAGS := -DNDEBUG=1
else
$(error Unsupported target, check Makefile.)
endif

LONG_BIT := $(shell getconf LONG_BIT)
ifeq ($(strip $(LONG_BIT)),32)
ARCHFLAGS := -m32 -mcpu=pentium4 -DARCH=32
ARCHNAME  := i386
else ($(strip $(LONG_BIT)),64)
ARCHFLAGS := -m64 -mcpu=sandybridge -mavx -mavx2 -DARCH=64
ARCHNAME  := x86_64
else
$(error Your platform is neither 32-bit nor 64-bit.)
endif

OUTDIR := $(SLNDIR)/build/$(ARCHNAME)/$(TARGET)
BUILD     := $(OUTDIR)/$(PROJECT)

SFILES   := $(shell cd $(PRJDIR)/src && find -type f -name '*.s')
CFILES   := $(shell cd $(PRJDIR)/src && find -type f -name '*.c')
CPPFILES := $(shell cd $(PRJDIR)/src && find -type f -name '*.cc')

if ($(strip $(SFILES) $(CFILES) $(CPPFILES)),)
$(error No source files were found.)
endif

ifeq ($(strip $(shell which gcc)),)
$(error The gcc binary was not found in your PATH.)
endif
CC := gcc
ifeq ($(strip $(shell which g++)),)
$(error The g++ binary was not found in your PATH.)
endif
CXX := g++
ifeq ($(strip $(shell which gold)),)
$(warning GNU gold linker was not found. Falling back to ld...)
ifeq ($(strip $(shell which ld)),)
$(error The gold/ld binaries were not found in your PATH.)
endif
LD := ld
else
LD := gold
endif
ifeq ($(strip $(shell which python3)),)
$(error The python3 binary was not found in your PATH.)
endif
PY := python3

SFLAGS :=
CFLAGS := $(ARCHFLAGS) -mtune=generic -O2 -mfpmath=sse -c -x c -std=c11 -Wall \
	$(PLTFLAGS) $(TGTFLAGS)
CXXFLAGS := $(ARCHFLAGS) -mtune=generic -O2 -mfpmath=sse -c -x c++ -std=c++11 \
	-Wall $(PLTFLAGS) $(TGTFLAGS)
LDFLAGS := -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc \
	-L$(SLNDIR)/deps/lib$(LONG_BIT)/$(TARGET) -llz4 -lsfml -lboost_locale \
	-lboost_filesystem -lboost_system -shared
INCLUDES := -I $(SLNDIR)/deps/include -iquote $(PRJDIR)/src

.PHONY: all assemble compilec compilecxx link clean distclean

all: assemble compilec compilecxx link

assemble:
	@mkdir -p $(BUILD)/code
	@for SFILE in $(SFILES) ; do \
		OUTFILE=$$(echo $$SFILE | sed -e 's:/:+:')
		$(AS) $(SFLAGS) src/$$SFILE -o $(BUILD)/code/$$OUTFILE.o ; \
	done

compilec:
	@mkdir -p $(BUILD)/code
	@for CFILE in $(CFILES) ; do \
		OUTFILE=$$(echo $$CFILE | sed -e 's:/:+:')
		$(CC) $(CFLAGS) $(INCLUDES) src/$$CFILE $(BUILD)/code/$$OUTFILE.o ; \
	done

compilecxx:
	@mkdir -p $(BUILD)/code
	@for CPPFILE in $(CPPFILES) ; do \
		OUTFILE=$$(echo $CPPFILE | sed -e 's:/:+:')
		$(CXX) $(CXXFLAGS) $(INCLUDES) src/$$CPPFILE \
		$(BUILD)/code/$$OUTFILE.o ; \
	done

link:
	@$(LD) $(LDFLAGS) -o $(OUTDIR)/$(OUTNAME) \
		$$(find $(BUILD)/code -type f -name '*.o')

clean:
	@rm -rf $(BUILD)

distclean:
	@rm -rf $(SLNDIR)/build
