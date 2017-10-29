/*
 *  car.cpp:
 *
 *  `CAR` CLASS.
 *
 *  (c) 2017, Jacek Pierzchlewski, jacek@pierzchlewski.com
 *
 *  License:  BSD 2-CLAUSE.
 */
#include <sstream>
#include <iostream>

#include "car.h"

/*****************************************************************************/
/*                                                                           */
/* `Car` CLASS:  INTERFACE.                                                  */
/*                                                                           */
/*****************************************************************************/
void Car::fuel_up(double dLitres_)
{
/*
 *  FUEL UP THE CAR.
 *
 *  Parameters:
 *
 *    dLitres_:   [double]   Volume which will be fueled up in litres.
 *
 */

    dLitresInTank += dLitres_;

    _print_fueling(dLitres_);
    _print_fuel_left();
}

void Car::drive(unsigned int iKM_)
{
/*
 *  LET THE CAR DRIVE.
 *
 *  Parameters:
 *
 *    iKM_:   [unsigned int]   Kilometers to drive.
 *
 */

    // Is there any fuel in the tank?
    if (_is_tank_empty() == true)
    {
        _print_tank_is_empty();
        return;
    }
    _print_requested_km(iKM_);

    // How many kilometers is it possible to drive with the current fuel?
    double dKMToEmpty = _kilometers_to_empty();

    // How many kilometers the car will drive
    double dKMCarWillDrive;

    // Is there enough fuel in the tank?
    if(dKMToEmpty >= iKM_)
    {
        // Yes, there is enough fuel, the car will drive what was requested
        dKMCarWillDrive = iKM_;
    }
    else
    {
        // No, there is not enough fuel, car will drive only what it can
        dKMCarWillDrive = dKMToEmpty;
       _print_warning_not_enough_fuel(dKMCarWillDrive);
    }

    // Driving is here: burn fuel and update mileagwe
    _burn_fuel(dKMCarWillDrive);
    _update_mileage(dKMCarWillDrive);

    // Print how many kilometers the car drove and the fuel left
    _print_drove_km(dKMCarWillDrive);
    _print_fuel_left();

    return;
}

void Car::print_mileage() const
{
/*
 *  PRINT MILEAGE OF THE CAR.
 *
 */
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << strCol << " car mileage is " << dMileage << " kilometers.";
    std::cout << std::endl << std::endl;
}

Car::Car(std::string strCol_, double dFuelEconomy_)
{
/*
 *  CONSTRUCTOR.
 *
 *  Parameters:
 *
 *    strCol_:        [std::string]   Color of the car
 *
 *    dFuelEconomy_:  [double]        Fuel economy (litres p. 100 km)
 *
 */

    // Store the color and fuel economy
    strCol = strCol_;
    dFuelEconomy = dFuelEconomy_;

    // When the cat leaves the factory there are:
    dLitresInTank = 2.0;  // 2 litres of fuel in the tank
    dMileage = 3.0;       // 3 kilometers on the odometer
}

/*****************************************************************************/
/*                                                                           */
/* `Car` CLASS:  PRINTING FUNCTIONS  (PRIVATE).                              */
/*                                                                           */
/*****************************************************************************/
void Car::_print_tank_is_empty() const
{
/*
 *  PRINT THAT THE TANK IS EMPTY.
 */
    std::cout << "         " << strCol << " car: ";
    std::cout << "there is no more fuel in the tank!";
    std::cout << std::endl << std::endl;
}

void Car::_print_fuel_left() const
{
/*
 *  PRINT HOW MUCH FUEL IS LEFT.
 */

    std::cout.precision(1);
    std::cout << std::fixed;

    if (dLitresInTank == 0)
    {
        _print_tank_is_empty();
    }
    else
    {
        std::cout << "         " << strCol << " car: there is ";
        std::cout << dLitresInTank << " litres left in the tank.";
        std::cout << std::endl << std::endl;
    }
}

void Car::_print_fueling(double dLitres_) const
{
/*
 *  PRINT INFO ABOUT FUELING PROCESS.
 *
 *  Parameters:
 *
 *    dLitres_:  [double]  Volume which was fueled up.
 *
 */
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "FUELING: " << strCol << " car: +" << dLitres_;
    std::cout << " litres." << std::endl;
}

void Car::_print_warning_not_enough_fuel(double dKMToEmpty_) const
{
/*
 *  PRINT WARNING THAT THERE IS NOT ENOUGH FUEL FOR REQUESTED DISTANCE.
 *
 *  Parameters:
 *
 *    dKMToEmpty_:  [double]   Requested distance in kilometers.
 *
 */
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "WARNING: " << strCol << " car has fuel only for ";
    std::cout << dKMToEmpty_ << " kilometers!" << std::endl;
}

void Car::_print_requested_km(unsigned int iKM_) const
{
/*
 *  PRINT REQUESTED DISTANCE.
 *
 *  Parameters:
 *
 *    dKMToEmpty_:  [double]   Requested distance in kilometers.
 *
 */
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "DRIVING: " << strCol << " car is requested to drive ";
    std::cout << iKM_ << " kilometers." << std::endl;

}

void Car::_print_drove_km(double dKMCarDrove_) const
{
/*
 *  PRINT DROVE DISTANCE.
 *
 *  Parameters:
 *
 *    dKMCarDrove_:  [double]   Distance the car drove in kilometers.
 *
 */

    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "DRIVING: " << strCol << " car drove for ";
    std::cout << dKMCarDrove_ << " kilometers." << std::endl;
}

/*****************************************************************************/
/*                                                                           */
/* `Car` CLASS:  DRIVING FUNCTIONS  (PRIVATE).                               */
/*                                                                           */
/*****************************************************************************/
void Car::_burn_fuel(double dKM_)
{
/*
 *  BURN FUEL WHILE DRIVING.
 *
 *  Parameters:
 *
 *    dKM_ :   [double]   Kilomters the car drove.
 *
 */
    if (dKM_ == _kilometers_to_empty())
    {
        dLitresInTank = 0;
    }
    else
    {
        double dBurnedFuel = dKM_ / 100 * dFuelEconomy;
        dLitresInTank -= dBurnedFuel;
    }

}

void Car::_update_mileage(double dKM_)
{
/*
 *  UPDATE MILEAGE ODOMETER.
 *
 *  Parameters:
 *
 *    dKM_ :   [double]   Kilomters to be added to the odometer.
 *
 */
    dMileage += dKM_;
}

/*****************************************************************************/
/*                                                                           */
/* `Car` CLASS:  DASHBOARD FUNCTIONS  (PRIVATE).                             */
/*                                                                           */
/*****************************************************************************/
bool Car::_is_tank_empty() const
{
/*
 *  IS THE FUEL TANK EMPTY?
 *
 *  Return:
 *
 *    ~ :   [bool]   true => fuel tank is empty.
 *
 */
    return (dLitresInTank == 0);
}

double Car::_kilometers_to_empty()
{
/*
 *  HOW MANY KILOMTERS TO EMPTY TANK?
 *
 *  Return:
 *
 *    ~ :   [double]   The number of kilometers to empty tank.
 *
 */
    return dLitresInTank / dFuelEconomy * 100;
}

