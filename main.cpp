#include <iostream>
#include <string>

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

int mainMenu();
SurgeryType surgeryMenu();
MedicationType pharmacyMenu();

int validateInput(string);
int getDays();

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

  // selected options
  int mainOption;
  SurgeryType surgeryOption;
  MedicationType pharmacyOption;

  // run interface
  do
  {
    mainOption = mainMenu();
    switch (mainOption)
    {
    case 1: // add surgery type
      surgeryOption = surgeryMenu();
      surgery.addSurgery(surgeryOption, patient);
      break;
    case 2: // add medication type
      pharmacyOption = pharmacyMenu();
      pharmacy.addMedication(pharmacyOption, patient);
      break;
    case 3: // add day(s) to stay
      patient.addDays(getDays());
      break;
    case 4: // print out bill
      cout << "Duration of stay: ";
      cout << patient.getDaysSentInHospital();
      cout << endl;

      cout << "Total Charges: $";
      cout << patient.getCharges();
      cout << endl;
    }
  } while (mainOption != 4); // quits if option was print out bill

  return 0;
}

bool validateInput(string input, int maxIndex)
{
  /*
    Checks for valid list index input:
      - Single digit length
      - Numeric input
      - values greater than 1
      - values less than the max acceptable index
  */
  if (input.length() != 1)
  {
    cout << "!! Selection text does not match expected length !!";
    return false;
  }
  else if (!isdigit(input.front()))
  {
    cout << "!! Selection text is not numeric !!";
    return false;
  }
  else if (stoi(input) < 1 && stoi(input) > maxIndex)
  {
    cout << "!! Selected index is outside of acceptable range !!";
    return false;
  }
  else
    return true;
}

int getDays()
{
  // loop for user input and validation
  string input;
  while (true)
  {
    cout << "\nDay(s) > ";
    getline(cin, input);

    if (input.length() < 1)
    {
      cout << "!! Please enter a value !!";
    }

    bool isNumber = true;
    for (int i = 0; i < input.length(); i++)
    {
      if (!isdigit(input.at(i)))
      {
        isNumber = false;
        break;
      }
    }
    if (!isNumber)
    {
      cout << "!! Days entered is not a numeric value !!";
    }
    else if (stoi(input) < 0)
    {
      cout << "!! Days cannot be negative !!";
    }
    else
      break;
  }

  return stoi(input);
}

int mainMenu()
{
  // display menu
  cout << "Select an option:" << endl;
  cout << "  1) Surgery" << endl;
  cout << "  2) Medication" << endl;
  cout << "  3) Add day(s) to stay" << endl;
  cout << "  4) Check out" << endl;

  // loop for user input and validation
  string selection;
  do
  {
    cout << "\n> ";
    getline(cin, selection);
  } while (!validateInput(selection, 4));

  return stoi(selection);
}

SurgeryType surgeryMenu()
{
  // display menu
  cout << "Select a surgery:" << endl;
  cout << "  1) Appendectomy" << endl;
  cout << "  2) Hepatic Resection" << endl;
  cout << "  3) Arthroscopy" << endl;
  cout << "  4) Laparoscopy" << endl;
  cout << "  5) Gastric Bypass" << endl;
  cout << "  6) Exit menu" << endl;

  // loop for user input and validation
  string selection;
  do
  {
    cout << "\n> ";
    getline(cin, selection);
  } while (!validateInput(selection, 6));

  // return appropriate surgery enum
  // default (option 6) will add nothing in addSurgery() function
  switch (stoi(selection))
  {
  case 1:
    return APPENDECTOMY;
  case 2:
    return HEPATIC_RESECTION;
  case 3:
    return ARTHROSCOPY;
  case 4:
    return LAPAROSCOPY;
  case 5:
    return GASTRIC_BYPASS;
  default:
    return NO_SURGERY;
  }
}

MedicationType pharmacyMenu()
{
  // display menu
  cout << "Select a medication:" << endl;
  cout << "  1) Gabapentin" << endl;
  cout << "  2) Vicodin" << endl;
  cout << "  3) Metformin" << endl;
  cout << "  4) Hydrocodone" << endl;
  cout << "  5) Acetaminophen" << endl;
  cout << "  6) Exit menu" << endl;

  // loop for user input and validation
  string selection;
  do
  {
    cout << "\n> ";
    getline(cin, selection);
  } while (!validateInput(selection, 6));

  // return appropriate medication enum
  // default (option 6) will add nothing in addMedication() function
  switch (stoi(selection))
  {
  case 1:
    return GABAPENTIN;
  case 2:
    return VICODIN;
  case 3:
    return METFORMIN;
  case 4:
    return HYDROCODONE;
  case 5:
    return ACETAMINOPHEN;
  default:
    return NO_MEDICATION;
  }
}