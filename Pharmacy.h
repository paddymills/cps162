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
  ACETAMINOPHEN
};

class Pharmacy
{
public:
  void addMedication(MedicationType, PatientAccount &);
};
#endif