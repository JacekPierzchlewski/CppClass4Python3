
C++ FOR PYTHON3.

EXAMPLE OF USING C++ CLASS IN PYTHON3, PART1: THE SIMPLEST MODULE.


INTRODUCTION
-------------------------------------------------------------------------------
This subdirectory contains an example with the simplest possible Python3 module
written in C++. Its purpose is to show the basic structure of a Python3 module
coded in C++.

This module is `dummy`, as it provides no functionality. Yet, it can be compiled
and loaded into Python3.


RUNNING
-------------------------------------------------------------------------------

1. COMPILE.
    To compile the module run:

    $ make simplest_py_module

    It will create Python3 module `simplest.cpython-3Xm.so` which now can
    be loaded to Python.

2. IMPORT PYTHON MODULE.
    Open cPython3 interpreter (python3 or ipython3) in the current directory.

    $ python3

    Now you can load the compile module:

    >>> import simplest

3. CLEANINIG UP.
    To clean up the directory run:

    $ make clean.

    It will remove `simplest.cpython-3Xm.so`, and `build` and `__pycache__`
    directories.


CONTENTS
-------------------------------------------------------------------------------
Important files in this subdirectory:

1. compile_SIMPLEST_py_module:   Python3 script which compiles
                                 `simplest_py_module.cpp` into a Python3 module.

2. simplest_py_module.cpp:       The simplest possible, dummy Python3 module
                                 written in C++.

AUTHOR
-------------------------------------------------------------------------------
(c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
http://www.speedupcode.com


LICENSE
-------------------------------------------------------------------------------
BSD 2-CLAUSE.
