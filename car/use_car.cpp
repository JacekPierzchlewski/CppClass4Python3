/*
 *  use_car.cpp:
 *
 *  C++ EXAMPLE OF USING `CAR` CLASS.
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */
#include "car.h"

int main()
{
    // Create two cars
    Car carRed("Blue", 5.5);
    Car carSilver("Silver", 12);

    // Fuel up the cars
    carRed.fuel_up(40);
    carSilver.fuel_up(30);

    // Drive the cars
    carRed.drive(500);
    carSilver.drive(200);

    // Fuel up only the silver car
    carSilver.fuel_up(40);

    // Drive the cars again
    carRed.drive(400);
    carSilver.drive(100);

    // Print the mileage of the cars
    carRed.print_mileage();
    carSilver.print_mileage();
}
