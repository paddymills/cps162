#include "PatientAccount.h"

class PatientAccount;

enum SurgeryType
{
  Appendectomy,
  HepaticResection,
  Arthroscopy,
  Laparoscopy,
  GastricBypass
};

#ifndef SURGERY_H
#define SURGERY_H
class Surgery
{
public:
  void addSurgery(SurgeryType, PatientAccount &);
};

#endif