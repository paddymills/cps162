#include "PatientAccount.h"
#include <iostream>
#include <iomanip>

PatientAccount::PatientAccount()
{
  daysSpentInHospital = 0;
  dailyRate = 60.0;
}

PatientAccount::~PatientAccount()
{
  items.clear();
}

void PatientAccount::addDays(int days)
{
  daysSpentInHospital += days;
}

void PatientAccount::addCharge(double cost, string caption)
{
  charges.push_back(cost);
  items.push_back(caption);
}

void PatientAccount::displaySummary()
{
  const int CAPTION_WID = 20;
  const int AMOUNT_WID = 10;
  cout << setprecision(2) << fixed;

  cout << "Bill Summary" << endl;
  cout << "===============================" << endl;

  // output stay duration/days
  cout << left << setw(CAPTION_WID);
  cout << "Duration of stay";
  cout << ": ";
  cout << daysSpentInHospital;
  cout << " days";
  cout << endl;

  cout << left << setw(CAPTION_WID);
  cout << "Daily Rate";
  cout << "$";
  cout << right << setw(AMOUNT_WID);
  cout << dailyRate;
  cout << endl;

  cout << left << setw(CAPTION_WID);
  cout << "Cost of stay";
  cout << "$";
  cout << right << setw(AMOUNT_WID);
  cout << dailyRate * daysSpentInHospital;
  cout << endl;

  cout << " ----------------------------- " << endl;

  // output charges
  for (int i = 0; i < charges.size(); i++)
  {
    cout << left << setw(CAPTION_WID);
    cout << items[i];
    cout << "$";
    cout << right << setw(AMOUNT_WID);
    cout << charges[i];
    cout << endl;
  }

  cout << "===============================" << endl;

  // output total
  cout << left << setw(CAPTION_WID);
  cout << "Total Charges";
  cout << "$";
  cout << right << setw(AMOUNT_WID);
  cout << getCharges();
  cout << endl;
}

int PatientAccount::getDaysSentInHospital() const
{
  return daysSpentInHospital;
}

double PatientAccount::getCharges() const
{
  double total = 0.0;
  for (int i = 0; i < charges.size(); i++)
  {
    total += charges[i];
  }

  total += dailyRate * daysSpentInHospital;

  return total;
}