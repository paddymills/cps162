#include <iostream>
#include "CargoShip.h"
#include "Ship.h"

using namespace std;

CargoShip::CargoShip() : Ship::Ship()
{
  cargoCapacity = 0;
}

void CargoShip::setCapacity(int containers)
{
  cargoCapacity = containers;
}

int CargoShip::getCapacity()
{
  return cargoCapacity;
}

void CargoShip::print()
{
  // print name and cargo container capacity

  cout << this->getName() << endl;
  cout << "\tCapacity: ";
  cout << cargoCapacity;
  cout << " tonnes" << endl;
}