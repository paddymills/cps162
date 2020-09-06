#include "PatientAccount.h"

class PatientAccount;

enum MedicationType
{
  Gabapentin,
  Vicodin,
  Metformin,
  Hydrocodone,
  Acetaminophen
};

#ifndef PHARMACY_H
#define PHARMACY_H
class Pharmacy
{
public:
  void addMedication(MedicationType, PatientAccount &);
};
#endif