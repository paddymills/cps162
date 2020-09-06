#include <iostream>

using namespace std;

int displayPatientMenu();

int main()
{
  /*
    main program execution:
      1) Pick surgerytype, medication type, check out
      2) Display total charges
  */

  return 0;
}

int displayPatientMenu()
{
  string selection;

  cout << "Select an option:" << endl;
  cout << "\t1) Surgery" << endl;
  cout << "\t2) Medication" << endl;
  cout << "\t3) Check out" << endl;

  do
  {
    cout << "\n> ";
    cin >> selection;

    switch (selection)
    {
    case "1":
    case "2":
    case "3":
      return int(selection);
    case "":
      cout << "\nEmpty string: terminating";
      return 0;
    default:
      cout << "\nInvalid Selection\n";
    }
  } while (selection != "")
}
