#
# MIT License
# 
# Copyright (c) 2020 Piyush Itankar <pitankar@gmail.com>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

# Source code paths
ROOT_DIR = $(shell pwd)
SRC = src
SRC_V = src_v
INC = $(ROOT_DIR)/src_v/include/

# Tools and flags
VERILATOR = verilator
VERILATOR-FLAGS = --lint-only -Wall 
VERIFY-FLAGS = -Wall --cc -CFLAGS "-std=c++11 -I$(INC)" --exe

lint:
ifeq (, $(filter-out lint, $(MAKECMDGOALS)))
	@echo "Usage: make lint module [other modules space separated]"
endif

# Handle linting commands as a group
ifeq (lint, $(word 1, $(MAKECMDGOALS)))
TOP = $(filter-out lint, $(MAKECMDGOALS))

$(TOP):
	$(VERILATOR) $(VERILATOR-FLAGS) --top-module $@ $(SRC)/$@.sv
endif

#dummy target, print the usage
verify:
ifeq (, $(filter-out verify, $(MAKECMDGOALS)))
	@echo "Usage: make verify module [other modules space separated]"
endif

# Handle Verification commands as a group
ifeq (verify, $(word 1, $(MAKECMDGOALS)))
TOP = $(filter-out verify, $(MAKECMDGOALS))

.SILENT:
$(TOP):
	echo "[Building $@]"
	$(VERILATOR) $(VERIFY-FLAGS) $(SRC)/$@.sv $(SRC_V)/$@.cpp
	make -C obj_dir/ -f V$@.mk
	./obj_dir/V$@
endif

.SILENT:
clean:
	rm -rf obj_dir/

.PHONY: verify clean lint
