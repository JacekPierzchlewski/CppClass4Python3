#
#  use_car.py:
#
#  PYTHON SCRIPT WHICH USES C++ `Car` CLASS VIA C++ TO PYTHON INTERFACE.
#
#  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
#
#  License:  BSD 2-CLAUSE.
#

# Import Python wrapping class for C++ `Car` class
from car import car

def main():

    # Create two cars
    carRed = car("Blue", 5.5)
    carSilver = car("Silver", 12)

    # Fuel up the cars
    carRed.fuel_up(40)
    carSilver.fuel_up(30)

    # Drive the cars
    carRed.drive(500)
    carSilver.drive(200)

    # Fuel up only the silver car
    carSilver.fuel_up(40)

    # Drive the cars again
    carRed.drive(400)
    carSilver.drive(100)

    # Print the mileage of the cars
    carRed.print_mileage()
    carSilver.print_mileage()


if __name__ == "__main__":
    main()
