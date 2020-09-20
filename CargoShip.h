#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include "Ship.h"

class CargoShip : public Ship
{
private:
  int cargoCapacity;

public:
  CargoShip();
  void setCapacity(int);
  int getCapacity();

  // overload print from base Ship
  virtual void print();
};

#endif