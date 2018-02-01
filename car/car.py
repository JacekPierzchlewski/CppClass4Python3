#
#  car.py:
#
#  TOP INTERFACE: DEFINITION OF PYTHON WRAPPING CLASS FOR C++ `Car` CLASS.
#
#  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
#  License:  BSD 2-CLAUSE.
#
try:
    import cCar
except:
    strErr = "\n\n`cCar` module not found, "
    strErr += "run `$ make car_py_module`! \n"
    raise RuntimeError(strErr)

class car():

    def __init__(self, color, fueleconomy):

        # Construct the `Car` object and store a Python capsule with
        # a C++ pointer to the object
        #
        # Take a look at function `construct` in `car2py.cpp` file
        self.carCapsule = cCar.construct(color, fueleconomy)

    def fuel_up(self, litres):
        """
        Python wrapper for `Car::fuel_up`
        """
        cCar.fuel_up(self.carCapsule, litres)

    def drive(self, kilometers):
        """
        Python wrapper for `Car::drive`
        """
        cCar.drive(self.carCapsule, kilometers)

    def print_mileage(self):
        """
        Python wrapper for `Car::print_mileage`
        """
        cCar.print_mileage(self.carCapsule)

    def __delete__(self):
        cCar.delete_object(self.carCapsule)
