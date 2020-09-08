
#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include <string>
#include <vector>
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

class PatientAccount
{
private:
  int daysSpentInHospital;
  double dailyRate;
  vector<double> charges;
  vector<string> items;

public:
  PatientAccount();
  ~PatientAccount();
  void addDays(int);
  void addCharge(double, string);
  void displaySummary();
  int getDaysSentInHospital() const;
  double getCharges() const;
  friend void Pharmacy::addMedication(MedicationType, PatientAccount &);
  friend void Surgery::addSurgery(SurgeryType, PatientAccount &);
};

#endif