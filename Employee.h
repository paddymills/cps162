#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
  private:
    string name;
    int idNumber;
    string department;
    string position;

  public:
    Employee(string n, int id, string dept, string pos)
    {
      name = n;
      idNumber = id;
      department = dept;
      position = pos;
    }
    Employee(string n, int id)
    {
      name = n;
      idNumber = id;
      department = "";
      position = "";
    }
    Employee()
    {
      name = "";
      idNumber = 0;
      department = "";
      position = "";
    }

    void setName(string n)
      { name = n; }
    void setIdNumber(int id)
      { idNumber = id; }
    void setDepartment(string dept)
      { department = dept; }
    void setPosition(string pos)
      { position = pos; }

    string getName() const
      { return name; }
    int getIdNumber() const
      { return idNumber; }
    string getPosition() const
      { return department; }
    string getDepartment() const
      { return position; }
};

#endif