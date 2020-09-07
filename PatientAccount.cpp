#include "PatientAccount.h"

PatientAccount::PatientAccount()
{
  daysSpentInHospital = 0;
  charges = 0.0;
}

void PatientAccount::addDays(int days)
{
  daysSpentInHospital += days;
}

void PatientAccount::addCharge(double cost)
{
  charges += cost;
}

int PatientAccount::getDaysSentInHospital() const
{
  return daysSpentInHospital;
}

double PatientAccount::getCharges() const
{
  return daysSpentInHospital * 60.0 + charges;
}