#ifndef PHARMACY_H
#define PHARMACY_H

class PatientAccount;

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