#!/usr/bin/env make
## -*- coding: utf-8; mode: make; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#
# Copyright (C) 2017 Arqadium. All rights reserved.
#
# This Source Code Form is subject to the terms of the Mozilla Public License,
# version 2.0. If a copy of the MPL was not distributed with this file, you
# can obtain one at <http://mozilla.org/MPL/2.0/>.
#

ifeq ($(strip $(SLNDIR)),)
	$(error This Makefile cannot be called directly)
endif

PROJECT := engine
OUTNAME := playmochi

PRJDIR := $(SLNDIR)/src/$(PROJECT)

PLATFORM := $(shell uname -s)

ifeq ($(strip $(PLATFORM)),Linux)
	PLTFLAGS := -DLINUX=1
else
	ifeq ($(strip $(PLATFORM)),Darwin)
		PLTFLAGS := -DDARWIN=1
	else
		$(error Unsupported platform)
	endif
endif

ifeq ($(strip $(TARGET)),debug)
	TGTFLAGS := -UNDEBUG
else
	ifeq ($(strip $(TARGET)),release)
		TGTFLAGS := -DNDEBUG=1
	else
		$(error Unsupported target, check Makefile)
	endif
endif

LONG_BIT := $(shell getconf LONG_BIT)
ifeq ($(strip $(LONG_BIT)),32)
	ARCHFLAGS := -m32 -march=pentium4 -DARCH=32
	ARCHNAME  := i386
else
	ifeq ($(strip $(LONG_BIT)),64)
		ARCHFLAGS := -m64 -march=sandybridge -mavx -mavx2 -DARCH=64
		ARCHNAME  := x86_64
	else
		$(error Your platform is neither 32-bit nor 64-bit)
	endif
endif

OUTDIR := $(SLNDIR)/build/$(ARCHNAME)/$(TARGET)
BUILD     := $(OUTDIR)/$(PROJECT)

SFILES   := $(shell cd "$(PRJDIR)/src" && find -type f -name '*.s' | sed -e 's:./::')
CFILES   := $(shell cd "$(PRJDIR)/src" && find -type f -name '*.c' | sed -e 's:./::')
CPPFILES := $(shell cd "$(PRJDIR)/src" && find -type f -name '*.cc' | sed -e 's:./::')
HFILES   := $(shell cd "$(PRJDIR)/src" && find -type f -name '*.h' | sed -e 's:./::')
HPPFILES := $(shell cd "$(PRJDIR)/src" && find -type f -name '*.hh' | sed -e 's:./::')

ifeq ($(strip $(SFILES) $(CFILES) $(CPPFILES)),)
	$(error No source files were found)
endif

ifeq ($(strip $(shell which gcc)),)
	$(error The gcc binary was not found in your PATH)
endif
CC := gcc
ifeq ($(strip $(shell which g++)),)
	$(error The g++ binary was not found in your PATH)
endif
CXX := g++
ifeq ($(strip $(shell which ld.gold)),)
	$(warning GNU gold linker was not found. Falling back to ld..)
	ifeq ($(strip $(shell which ld)),)
		$(error The gold/ld binaries were not found in your PATH)
	endif
	LD := g++
else
	LD := g++ -fuse-ld=gold
endif
ifeq ($(strip $(shell which python3)),)
	$(error The python3 binary was not found in your PATH)
endif
PY := python3
ifeq ($(strip $(shell which clang-format)),)
	$(error The clang-format linter was not found in your PATH)
endif
LINT := clang-format

SFLAGS :=
CFLAGS := $(ARCHFLAGS) -mtune=generic -O2 -mfpmath=sse -c -x c -std=c11 -Wall \
	$(PLTFLAGS) $(TGTFLAGS)
CXXFLAGS := $(ARCHFLAGS) -mtune=generic -O2 -mfpmath=sse -c -x c++ -std=c++14 \
	-Wall $(PLTFLAGS) $(TGTFLAGS)
LDFLAGS := -L"$(SLNDIR)/deps/lib$(LONG_BIT)/$(TARGET)" -llz4 -lsfml-audio \
	-lsfml-graphics -lsfml-network -lsfml-window -lsfml-system \
	-lboost_locale -lboost_filesystem -lboost_system
INCLUDES := -I "$(SLNDIR)/deps/include" -iquote "$(PRJDIR)/src" -iquote \
	"$(SLNDIR)/src/lz4/src"

.PHONY: all lint assemble compilec compilecxx link clean distclean

all: lint assemble compilec compilecxx link

lint:
	@mkdir -p "$(BUILD)"
	@for CPPFILE in $(CPPFILES) ; do \
		$(LINT) --style=file "src/$$CPPFILE" > "$(BUILD)/templint" ; \
		mv -f "$(BUILD)/templint" "src/$$CPPFILE" ; \
	done
	@for HPPFILE in $(HPPFILES) ; do \
		$(LINT) --style=file "src/$$HPPFILE" > "$(BUILD)/templint" ; \
		mv -f "$(BUILD)/templint" "src/$$HPPFILE" ; \
	done
	@rm -f "$(BUILD)/templint"

assemble:
	@mkdir -p "$(BUILD)/code"
	@for SFILE in $(SFILES) ; do \
		OUTFILE=$$(echo "$$SFILE" | sed -e 's:/:+:') ; \
		$(AS) $(SFLAGS) "src/$$SFILE" -o "$(BUILD)/code/$$OUTFILE.o" ; \
	done

compilec:
	@mkdir -p "$(BUILD)/code"
	@for CFILE in $(CFILES) ; do \
		OUTFILE=$$(echo "$$CFILE" | sed -e 's:/:+:') ; \
		$(CC) $(CFLAGS) $(INCLUDES) "src/$$CFILE" -o \
			"$(BUILD)/code/$$OUTFILE.o" ; \
	done

compilecxx:
	@mkdir -p "$(BUILD)/code"
	@for CPPFILE in $(CPPFILES) ; do \
		OUTFILE=$$(echo "$$CPPFILE" | sed -e 's:/:+:') ; \
		$(CXX) $(CXXFLAGS) $(INCLUDES) "src/$$CPPFILE" -o \
			"$(BUILD)/code/$$OUTFILE.o" ; \
	done

link:
	@$(LD) $(LDFLAGS) -o "$(OUTDIR)/$(OUTNAME)" \
		$$(find "$(BUILD)/code" -type f -name '*.o')

clean:
	@rm -rf "$(BUILD)"

distclean:
	@rm -rf "$(SLNDIR)/build"
