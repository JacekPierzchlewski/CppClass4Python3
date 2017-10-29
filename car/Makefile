#
# Makefile for `Car` Python module written in C++.
#
#  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
#  License:  BSD 2-CLAUSE.
#

# Compiler and Python interpreter
CPYTHON3 = python3
CPP = g++

# C++ example
HEADERS = car.h
OBJECTS = car.o use_car.o
CPPNAME = use_car

# Python module
MODULE_SOURCE = car.cpp car2py.cpp
MODULE_COMPILE_SCRIPT = compile_CAR_py_module.py

%.o: %.cpp $(HEADERS)
		$(CPP) -c $<

# Build C++ application of `Car` class.
use_car_cpp: $(OBJECTS)
	$(CPP) -o $(CPPNAME) $(OBJECTS)

# Build Python `Car` module
car_py_module: $(MODULE_SOURCE) $(MODULE_COMPILE_SCRIPT) $(HEADERS)
	$(CPYTHON3) $(MODULE_COMPILE_SCRIPT) build_ext --inplace

# Clean up the current directory
.PHONY: clean
clean:
	rm -fR build
	rm -f *.so
	rm -f *.o
	rm -fR __pycache__
	rm -f use_car

