#include <iostream>
#include "Ship.h"

using namespace std;

Ship::Ship()
{
  name = "";
  buildYear = "";
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

void Ship::print()
{
  // print name and build year

  cout << name << endl;
  cout << "\tBuild Year: ";
  cout << buildYear << endl;
}