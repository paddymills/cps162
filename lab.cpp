#include <iostream>

#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

int main()
{
  // initialize ships
  const int NUM_SHIPS = 3;
  Ship *ships[NUM_SHIPS] = {
      new Ship(),
      new CargoShip(),
      new CruiseShip(),
  };

  // assign name, build year and capacity
  // Ship contructor
  ships[0]->setName("HMS Beagle");
  ships[0]->setBuildYear("1820");

  // CargoShip constructor
  ships[1]->setName("Edith Maersk");
  ships[1]->setBuildYear("2007");
  // must static_cast because Ship does not have setCapacity
  static_cast<CargoShip *>(ships[1])->setCapacity(156907);

  // CruiseShip constructor
  ships[2]->setName("RMS Titanic");
  ships[2]->setBuildYear("1911");
  // must static_cast because Ship does not have setCapacity
  static_cast<CruiseShip *>(ships[2])->setCapacity(2435);

  // iterate over ships and print them
  for (int i = 0; i < NUM_SHIPS; i++)
  {
    // print method overridden in each ship class
    ships[i]->print();
  }

  return 0;
}
