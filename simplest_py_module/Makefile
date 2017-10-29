#
# Makefile for Simplest Python3 module written in C++.
#
# (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
# License:  BSD 2-CLAUSE.
#

# Make variables
CPYTHON3 = python3
MODULE_SOURCE = simplest_py_module.cpp
MODULE_COMPILE_SCRIPT = compile_SIMPLEST_py_module.py

# Complile the Python module
simplest_py_module: $(MODULE_SOURCE) $(MODULE_COMPILE_SCRIPT)
	$(CPYTHON3) $(MODULE_COMPILE_SCRIPT) build_ext --inplace

# Clean up the current directory
.PHONY: clean
clean:
	rm -fR build
	rm -fR __pycache__
	rm -f *.so
