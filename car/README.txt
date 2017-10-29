C++ FOR PYTHON3.

EXAMPLE OF USING C++ CLASS IN PYTHON3, PART3: `CAR` CLASS IN PYTHON3.

INTRODUCTION
-------------------------------------------------------------------------------
This subdirectory contains example of using a real C++ class in Python3.

The class `Car` represents a virtual car. It is possible to fuel up and drive
the "car", and additionally, read its odometer. Every car has its own color
and fuel consumption, which are set when a new car is allocated. While driving,
the car is using fuel, which may eventually run out.

There is an example of using `Car` class in C++, a C++ to Python3 interface to
the class, and an example of using `Car` class in Python3.

The purpose of this example is to ilustrate the basics of making a Python3
module which facilitates C++ classes for Python3.


RUNNING
-------------------------------------------------------------------------------

1. COMPILE AND RUN C++ EXAMPLE.
    To compile the C++ example which uses `Car` class run:

    $ make use_car_cpp

    It will create `use_car` executable in the directory.

    Now run:

    $ ./use_car

    for a working C++ example of using `Car` class.


2. COMPILE PYTHON3 MODULE.
    To compile the module run:

    $ make car_py_module

    It will create Python3 module `cCar.cpython-3Xm.so` which can now be used
    by Python3.

3. RUN SCRIPT WHICH USES THE MODULE.
    Run:

    $ python3 use_car.py

    to run the Python3 script which uses `Car` class via C++ to Python3
    interface.

    Observe that that the output from this script is identical to the output
    from C++ example which uses `Car` class (./use_car).


4. CLEANINIG UP.
    To clean up the directory run:

    $ make clean.

    It will remove `cCar.cpython-3Xm.so`, .o compiled objects,
    compiled `./use_car` C++ example and `build` and `__pycache__` directories.


CONTENTS
-------------------------------------------------------------------------------
Important files in this subdirectory:

1. car.cpp:     Definition of C++ `Car` class.

2. car.h:       C++ header for `Car` class.

3. use_car.cpp  An example of C++ code which uses `Car` class.

4. car2py.cpp   Python3 module which provides `Car` class for Python.

5. car.py       Python3 wrapping class for C++ `Car` class.

6. compile_CAR_py_module:   Python3 script which compiles `car.cpp` and
                            `car2py.cpp` into a Python3 module.

7. use_car.py   Python3 script which uses C++ `Car` class via C++ to Python3
                interface.

AUTHOR
-------------------------------------------------------------------------------
(c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
http://www.speedupcode.com


LICENSE
-------------------------------------------------------------------------------
BSD 2-CLAUSE.
