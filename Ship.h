
#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

class Ship
{
private:
  string name;
  string buildYear;

public:
  Ship();
  void setName(string);
  void setBuildYear(string);
  string getName();
  string getBuildYear();

  // virtual print method to be overridden
  virtual void print();
};

#endif