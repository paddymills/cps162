#include "PatientAccount.h"

class PatientAccount;

#ifndef PHARMACY_H
#define PHARMACY_H

enum MedicationType
{
  GABAPENTIN,
  VICODIN,
  METFORMIN,
  HYDROCODONE,
  ACETAMINOPHEN,
  NO_MEDICATION
};

class Pharmacy
{
public:
  void addMedication(MedicationType, PatientAccount &);
};
#endif