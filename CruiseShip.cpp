#include <iostream>
#include "CruiseShip.h"
#include "Ship.h"

using namespace std;

CruiseShip::CruiseShip() : Ship::Ship()
{
  passengerCapacity = 0;
}

void CruiseShip::setCapacity(int passengers)
{
  passengerCapacity = passengers;
}

int CruiseShip::getCapacity()
{
  return passengerCapacity;
}

void CruiseShip::print()
{
  // print name and passenger capacity

  cout << this->getName() << endl;
  cout << "\tCapacity: ";
  cout << passengerCapacity;
  cout << " passengers" << endl;
}