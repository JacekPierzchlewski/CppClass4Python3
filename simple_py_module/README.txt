C++ FOR PYTHON3.

EXAMPLE OF USING C++ CLASS IN PYTHON3, PART2: A SIMPLE MODULE.

INTRODUCTION
-------------------------------------------------------------------------------
This subdirectory contains an example with a simple Python3 module written
in C++.

The module provides one five-argument function which prints the arguments
passed from Python3 and returns the first argument (of integer type) multiplied
by two.

The purpose of this example is to ilustrate how arguments are passed from
Python3 to C++ and vice-versa.

RUNNING
-------------------------------------------------------------------------------

1. COMPILE.
    To compile the module run:

    $ make simple_py_module

    It will create Python3 module `simple.cpython-3Xm.so` which now can
    be used by Python3.

2. RUN SCRIPT WHICH USES THE MODULE.
    Run:

    $ python3 use_simple_module.py

    to run the Python3 script which uses the module.


3. CLEANINIG UP.
    To clean up the directory run:

    $ make clean.

    It will remove `simple.cpython-3Xm.so`, and `build` and `__pycache__`
    directories.


CONTENTS
-------------------------------------------------------------------------------
Important files in this subdirectory:

1. compile_SIMPLE_py_module:   Python3 script which compiles
                               `simple_py_module.cpp` into a Python3 module.

2. simple_py_module.cpp:       A simple Python3 module written in C++.

3. use_simple_py_module.py:    Python3 script which uses the simple module.


AUTHOR
-------------------------------------------------------------------------------
(c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
http://www.speedupcode.com


LICENSE
-------------------------------------------------------------------------------
BSD 2-CLAUSE.
