#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

#include "Pharmacy.h"
#include "Surgery.h"

class PatientAccount
{
private:
  int daysSpentInHospital;
  double charges;

public:
  PatientAccount();
  void addDays(int);
  void addCharge(double);
  int getDaysSentInHospital() const;
  double getCharges() const;
  friend void Pharmacy::addMedication(MedicationType, PatientAccount &);
  friend void Surgery::addSurgery(SurgeryType, PatientAccount &);
};

#endif