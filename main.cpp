#include <iostream>
#include <string>

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

int mainMenu();
int pharmacyMenu();
int surgeryMenu();

int main()
{
  /*
    main program execution:
      1) Pick surgery type, medication type, check out
      2) Display total charges
  */

  // init objects
  PatientAccount patient;
  Pharmacy pharmacy;
  Surgery surgery;

  int option;
  do
  {
    option = mainMenu();
    switch (option)
    {
    case 1:
      surgery.addSurgery(patient);
      break;
    case 2:
      pharmacy.addMedication(patient);
      break;
    case 3:
      cout << "Total Charges: $";
      cout << patient.getCharges();
      cout << endl;
    }
  } while (option < 3);

  return 0;
}

int mainMenu()
{
  // display menu
  cout << "Select an option:" << endl;
  cout << "  1) Surgery" << endl;
  cout << "  2) Medication" << endl;
  cout << "  3) Check out" << endl;

  // loop for user input and validation
  string selection;
  while (true)
  {
    cout << "\n> ";
    getline(cin, selection);

    if (selection.length() == 1 && isdigit(selection.front()) && stoi(selection) > 0 && stoi(selection) <= 3)
      break;
    else
      cout << "\nInvalid Selection\n";
  }

  return stoi(selection);
}
