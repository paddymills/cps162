#include "Surgery.h"
#include "PatientAccount.h"

void Surgery::addSurgery(SurgeryType s, PatientAccount &p)
{
  switch (s)
  {
  case APPENDECTOMY:
    p.addCharge(5000.0, "Appendectomy");
    p.addDays(3);
    break;
  case HEPATIC_RESECTION:
    p.addCharge(10000.0, "Hepatic Resection");
    p.addDays(5);
    break;
  case ARTHROSCOPY:
    p.addCharge(3000.0, "Arthroscopy");
    p.addDays(2);
    break;
  case LAPAROSCOPY:
    p.addCharge(4500.0, "Laparoscopy");
    p.addDays(1);
    break;
  case GASTRIC_BYPASS:
    p.addCharge(8000.0, "Gastric Bypass");
    p.addDays(2);
    break;
  default:
    break;
  }
}