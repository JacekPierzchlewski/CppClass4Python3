/*
 *  car2py.cpp:
 *
 *  PYTHON MODULE INTERFACE TO `CAR`.
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */
#include <Python.h>
#include <iostream>
#include "car.h"


PyObject* construct(PyObject* self, PyObject* args)
{
/*
 *  C++/PYTHON `Car` OBJECT CONSTRUCTOR.
 *
 *  Function allocates a new `Car` object and returns Python capsule
 *  with a pointer to the allocated object.
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    cdCol_:         [const char*]  Car color.
 *
 *    dFuelEconomy_:  [double]       Fuel economy.
 *
 *  Returns (passed in PyObject*):
 *
 *    carCapsule:     [PyObject*]    Python capsule with a pointer to
 *                                   allocated `Car` object.
 *
 */
    // Arguments passed from Python
    const char* csCol_;    // Car color
    double dFuelEconomy_;  // Fuel economy

    // Process arguments passes from Python
    PyArg_ParseTuple(args, "sd",
                     &csCol_,
                     &dFuelEconomy_);

    // Allocate new `Car` object
    Car* car = new Car(csCol_, dFuelEconomy_);

    // Create a Python capsule with a pointer to `Car` object
    PyObject* carCapsule = PyCapsule_New((void *)car, "CarPtr", NULL);
    PyCapsule_SetPointer(carCapsule, (void *)car);

    // Return the Python capsule with the pointer to`Car` object
    return Py_BuildValue("O", carCapsule);   // "O" means "Python object"
}

PyObject* fuel_up(PyObject* self, PyObject* args)
{
/*
 *  C++/PYTHON WRAPPER FOR PUBLIC FUNCTION Car::fuel_up.
 *
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    carCapsule_:   [PyObject*]  Python capsule with a pointer to `Car` object.
 *
 *    dLitres_:      [double]     Volume which will be fueled up in litres.
 *
 */
    // Arguments passed from Python
    PyObject* carCapsule_;   // Capsule with the pointer to `Car` object
    double dLitres_;         // Volume which will be fueled up

    // Process arguments
    PyArg_ParseTuple(args, "Od",
                     &carCapsule_,
                     &dLitres_);

    // Get the pointer to `Car` object
    Car* car = (Car*)PyCapsule_GetPointer(carCapsule_, "CarPtr");

    // Call `fuel_up` function
    car->fuel_up(dLitres_);

    // Return nothing
    return Py_BuildValue("");
}

PyObject* drive(PyObject* self, PyObject* args)
{
/*
 *  C++/PYTHON WRAPPER FOR PUBLIC FUNCTION Car::drive.
 *
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    carCapsule_:  [PyObject*]      Python capsule with a pointer to
 *                                   `Car` object.
 *
 *    iKM_:         [unsigned int]   Kilometers to drive.
 *
 */
    // Arguments passed from Python
    PyObject* carCapsule_;   // Capsule with the pointer to `Car` object
    unsigned int iKM_;       // Kilomters to drive

    // Process arguments
    PyArg_ParseTuple(args, "OI",
                     &carCapsule_,
                     &iKM_);

    // Get the pointer to `Car` object
    Car* car = (Car*)PyCapsule_GetPointer(carCapsule_, "CarPtr");

    // Call `drive` function
    car->drive(iKM_);

    // Return nothing
    return Py_BuildValue("");
}

PyObject* print_mileage(PyObject* self, PyObject* args)
{
/*
 *  C++/PYTHON WRAPPER FOR PUBLIC FUNCTION Car::print_mileage.
 *
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    carCapsule_:  [PyObject*]      Python capsule with a pointer to
 *                                   `Car` object.
 */
    // Arguments passed from Python
    PyObject* carCapsule_;   // Capsule with the pointer to `Car` object

    // Process arguments
    PyArg_ParseTuple(args, "O",
                     &carCapsule_);

    // Get the pointer to `Car` object
    Car* car = (Car*)PyCapsule_GetPointer(carCapsule_, "CarPtr");

    // Call `print_mileage` function
    car->print_mileage();

    // Return nothing
    return Py_BuildValue("");
}

PyObject* delete_object(PyObject* self, PyObject* args)
{
/*
 *  C++/PYTHON `Car` OBJECT DESTRUCTOR.
 *
 *
 *  Parameters (passed in PyObject* `args`):
 *
 *    carCapsule_:  [PyObject*]      Python capsule with a pointer to
 *                                   `Car` object.
 */
    // Arguments passed from Python
    PyObject* carCapsule_;   // Capsule with the pointer to `Car` object

    // Process arguments
    PyArg_ParseTuple(args, "O",
                     &carCapsule_);

    // Get the pointer to `Car` object
    Car* car = (Car*)PyCapsule_GetPointer(carCapsule_, "CarPtr");

    // Delete the `Car` object
    delete car;

    // Return nothing
    return Py_BuildValue("");
}

PyMethodDef cCarFunctions[] =
{
/*
 *  Structures which define functions ("methods") provided by the module.
 */
    {"construct",                   // C++/Py Constructor
      construct, METH_VARARGS,
     "Create `Car` object"},

    {"fuel_up",                     // C++/Py wrapper for `fuel_up`
      fuel_up, METH_VARARGS,
     "Fuel up car"},

    {"drive",                       // C++/Py wrapper for `drive`
      drive, METH_VARARGS,
     "Drive the car"},

    {"print_mileage",               // C++/Py wrapper for `print_mileage`
      print_mileage, METH_VARARGS,
     "Print mileage of the car"},

    {"delete_object",               // C++/Py Destructor
      delete_object, METH_VARARGS,
     "Delete `Car` object"},

    {NULL, NULL, 0, NULL}      // Last function description must be empty.
                               // Otherwise, it will create seg fault while
                               // importing the module.
};


struct PyModuleDef cCarModule =
{
/*
 *  Structure which defines the module.
 *
 *  For more info look at: https://docs.python.org/3/c-api/module.html
 *
 */
   PyModuleDef_HEAD_INIT,
   "cCar",               // Name of the module.

   NULL,                 // Docstring for the module - in this case empty.

   -1,                   // Used by sub-interpreters, if you do not know what
                         // it is then you do not need it, keep -1 .

   cCarFunctions         // Structures of type `PyMethodDef` with functions
                         // (or "methods") provided by the module.
};


PyMODINIT_FUNC PyInit_cCar(void)
{
/*
 *   Function which initialises the Python module.
 *
 *   Note:  This function must be named "PyInit_MODULENAME",
 *          where "MODULENAME" is the name of the module.
 *
 */
    return PyModule_Create(&cCarModule);
}
