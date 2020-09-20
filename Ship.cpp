#include <iostream>
#include "Ship.h"

using namespace std;

Ship::Ship()
{
  name = "";
  buildYear = "";
}

Ship::Ship(string n, string year)
{
  name = n;
  buildYear = year;
}

void Ship::setName(string n)
{
  name = n;
}

void Ship::setBuildYear(string year)
{
  buildYear = year;
}

string Ship::getName()
{
  return name;
}

string Ship::getBuildYear()
{
  return buildYear;
}
