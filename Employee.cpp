#include <iostream>
#include <memory>
#include "Employee.h"

using namespace std;

void outputEmployee(Employee);

int main()
{
    // employee 1
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");

    // employee 2
    Employee *mark = new Employee("Mark Jones", 39119);
    mark->setDepartment("IT");
    mark->setPosition("Programmer");

    // employee 3
    unique_ptr<Employee> joy(new Employee());
    joy->setName("Joy Rogers");
    joy->setIdNumber(81774);
    joy->setDepartment("Manufacturing");
    joy->setPosition("Engineer");

    // output employees
    outputEmployee(susan);
    outputEmployee(*mark);
    outputEmployee(*joy);

    return 0;
}

void outputEmployee(Employee emp)
{
    cout << "Employee Name: " << emp.getName() << endl;
    cout << "Employee Id: " << emp.getIdNumber() << endl;
    cout << "Employee Department: " << emp.getDepartment() << endl;
    cout << "Employee Position: " << emp.getPosition() << endl;
    cout << "" << endl;
}
