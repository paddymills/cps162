#include "Pharmacy.h"

void Pharmacy::addMedication(MedicationType m, PatientAccount &p)
{
  switch (m)
  {
  case GABAPENTIN:
    p.addCharge(50.0);
    break;
  case VICODIN:
    p.addCharge(70.0);
    break;
  case METFORMIN:
    p.addCharge(25.0);
    break;
  case HYDROCODONE:
    p.addCharge(45.0);
    break;
  case ACETAMINOPHEN:
    p.addCharge(10.0);
    break;
  default:
    break;
  }
}