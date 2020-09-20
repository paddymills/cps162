#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship
{
private:
  int passengerCapacity;

public:
  CruiseShip();
  void setCapacity(int);
  int getCapacity();

  // overload print from base Ship
  virtual void print();
};

#endif