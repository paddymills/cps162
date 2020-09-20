#include <iostream>

#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

int main()
{
  const int NUM_SHIPS = 6;
  Ship *ships[NUM_SHIPS] = {
      new Ship(),
      new Ship(),
      new CruiseShip(),
      new CruiseShip(),
      new CargoShip(),
      new CargoShip(),
  };

  for (int i = 0; i < NUM_SHIPS; i++)
  {
    cout << "Ship " << i + 1 << ": ";
    ships[i]->print();
    cout << endl;
  }

  return 0;
}
