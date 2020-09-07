#include "PatientAccount.h"

class PatientAccount;

#ifndef SURGERY_H
#define SURGERY_H
enum SurgeryType
{
  APPENDECTOMY,
  HEPATIC_RESECTION,
  ARTHROSCOPY,
  LAPAROSCOPY,
  GASTRIC_BYPASS,
  NO_SURGERY
};
class Surgery
{
public:
  void addSurgery(SurgeryType, PatientAccount &);
};

#endif