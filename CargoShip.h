#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship
{
private:
  int capacity;

public:
  CargoShip();
  void setCapacity();
};

#endif