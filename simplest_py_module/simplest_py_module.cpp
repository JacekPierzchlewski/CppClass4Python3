/*
 *  simplest_py_module.cpp:
 *
 *  EXAMPLE OF THE SIMPLEST PYTHON3 MODULE WRITTEN IN C++.
 *
 *  This module is `dummy`, because it provides no methods.
 *  Nevertheless, it shows basic structure of source of a Python module
 *  written in C++.
 *
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */
#include <Python.h>

PyMethodDef simplestFunctions[] =
{
/*
 *  Structures which define functions ("methods") provided by the module.
 *  Empty in this case.
 */
};


struct PyModuleDef simplestModule =
{
/*
 *  Structure which defines the module.
 *
 *  For more info look at: https://docs.python.org/3/c-api/module.html
 *
 */
   PyModuleDef_HEAD_INIT,
   "simplest",             // Name of the module.

   NULL,                   // Docstring for the module - in this case empty.

   -1,                     // Used by sub-interpreters, if you do not know what
                           // it is then you do not need it, keep -1 .

   simplestFunctions       // Structures of type `PyMethodDef` with functions
                           // (or "methods") provided by the module.
};


PyMODINIT_FUNC PyInit_simplest(void)
{
/*
 *   Function which initialises the Python module.
 *
 *   Note:  This function must be named "PyInit_MODULENAME",
 *          where "MODULENAME" is the name of the module.
 *
 */
    return PyModule_Create(&simplestModule);
}
