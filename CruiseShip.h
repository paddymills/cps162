#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include "Ship.h"

class CruiseShip : public Ship
{
private:
  int passengerCapacity;

public:
  CruiseShip();
  void setPassengerCapacity(int);
  int getPassengerCapacity();
};

#endif