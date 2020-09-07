#include "Surgery.h"

void Surgery::addSurgery(SurgeryType s, PatientAccount &p)
{
  switch (s)
  {
  case APPENDECTOMY:
    p.addCharge(5000.0);
    break;
  case HEPATIC_RESECTION:
    p.addCharge(10000.0);
    break;
  case ARTHROSCOPY:
    p.addCharge(3000.0);
    break;
  case LAPAROSCOPY:
    p.addCharge(4500.0);
    break;
  case GASTRIC_BYPASS:
    p.addCharge(8000.0);
    break;
  default:
    break;
  }
}