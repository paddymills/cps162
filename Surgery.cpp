#include "Surgery.h"

void Surgery::addSurgery(SurgeryType s, PatientAccount &p)
{
  switch (s)
  {
  case SurgeryType::Appendectomy:
    p.addCharge(5000.0);
    break;
  case SurgeryType::HepaticResection:
    p.addCharge(10000.0);
    break;
  case SurgeryType::Arthroscopy:
    p.addCharge(3000.0);
    break;
  case SurgeryType::Laparoscopy:
    p.addCharge(4500.0);
    break;
  case SurgeryType::GastricBypass:
    p.addCharge(8000.0);
    break;
  }
}