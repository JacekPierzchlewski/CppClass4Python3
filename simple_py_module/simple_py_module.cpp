/*
 *  simple_py_module.cpp:
 *
 *  EXAMPLE OF A SIMPLE PYTHON3 MODULE WRITTEN IN C++.
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */

#include <Python.h>
#include <iostream>

PyObject* print_variables(PyObject* self, PyObject* args)
{
/*
 *  Function which prints five arguments of a different type passed to
 *  the function from Python3.
 *
 *  The arguments passed from Python3 are of type  1: int, 2: long int,
 *  3: unsigned int, 4: const char*, 5: double.
 *
 *  Additionally, function returns the first argument multiplied by two.
 *
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    iInteger_:          [int]             Integer argument.
 *
 *    iLongInteger_:      [long int]        Long integer argument.
 *
 *    iUnsignedInteger_:  [unsigned int]    Unsigned integer argument.
 *
 *    csString_:          [const char*]     String argument.
 *
 *    dDouble_:           [double]          Double argument.
 *
 *
 *   Returns (passed in PyObject*):
 *
 *     i2Integer:  [int]   The 1st argument (integer) multiplied by 2.
 */

    // Arguments passed from Python
    int iInteger_;
    long int iLongInteger_;
    unsigned int iUnsignedInteger_;
    const char* csString_;
    double dDouble_;

    // Process arguments
    // Description of this function: https://docs.python.org/2/c-api/arg.html
    PyArg_ParseTuple(args, "iLIsd",
                     &iInteger_,          // `i` in "iLIscd"
                     &iLongInteger_,      // `L` in "iLIscd"
                     &iUnsignedInteger_,  // `I` in "iLIscd"
                     &csString_,          // `s` in "iLIscd"
                     &dDouble_            // `d` in "iLIscd"
                     );

    // Print the given arguments
    std::cout << "Integer given: " << iInteger_ << std::endl;
    std::cout << "Long integer given: " << iLongInteger_ << std::endl;
    std::cout << "Unsigned integer given: " << iUnsignedInteger_ << std::endl;
    std::cout << "String given: " << csString_ << std::endl;
    std::cout << "Double given: " << dDouble_ << std::endl;

    // Multiply the first argument (Integer) x2 and return it
    int i2Integer = 2 * iInteger_;

    // Return the multiplied argument
    return Py_BuildValue("i", i2Integer);
}


PyMethodDef simpleFunctions[] =
{
/*
 *  Structures which define functions ("methods") provided by the module.
 */
    {"print_variables",
      print_variables, METH_VARARGS,
     "Print variables "},
    {NULL, NULL, 0, NULL}      // Last function description must be empty.
                               // Otherwise, it will create seg fault while
                               // importing the module.
};


struct PyModuleDef simpleModule =
{
/*
 *  Structure which defines the module.
 *
 *  For more info look at: https://docs.python.org/3/c-api/module.html
 *
 */
   PyModuleDef_HEAD_INIT,
   "simple",             // Name of the module.

   NULL,                 // Docstring for the module - in this case empty.

   -1,                   // Used by sub-interpreters, if you do not know what
                         // it is then you do not need it, keep -1 .

   simpleFunctions       // Structures of type `PyMethodDef` with functions
                         // (or "methods") provided by the module.
};


PyMODINIT_FUNC PyInit_simple(void)
{
/*
 *   Function which initialises the Python module.
 *
 *   Note:  This function must be named "PyInit_MODULENAME",
 *          where "MODULENAME" is the name of the module.
 *
 */
    return PyModule_Create(&simpleModule);
}
