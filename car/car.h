/*
 *  car.h:
 *
 *  `CAR` CLASS HEADER.
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */
#include <sstream>

class Car
{
    public:

        // Full up the car
        void fuel_up(double);

        // Drive the car
        void drive(unsigned int);

        // What is the mileage?
        void print_mileage() const;

        // Constructor
        Car(std::string, double);

    private:
        std::string strCol;         // Color of the car

        double dLitresInTank;        // Fuel in the tank
        double dMileage;             // Mileage on odometer
        double dFuelEconomy;         // Fuel economy

        // Printing functions:
        void _print_tank_is_empty() const;
        void _print_fuel_left() const;
        void _print_fueling(double) const;
        void _print_warning_not_enough_fuel(double) const;
        void _print_requested_km(unsigned int) const;
        void _print_drove_km(double) const;

        // Driving functions:
        void _burn_fuel(double);       // burn fuel
        void _update_mileage(double);  // update mileage

        // Dashboard functions:
        bool _is_tank_empty()  const;   // is the tank empty?
        double _kilometers_to_empty();  // how many kilometers to empty?
};
