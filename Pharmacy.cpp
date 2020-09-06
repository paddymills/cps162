#include "Pharmacy.h"

void Pharmacy::addMedication(MedicationType m, PatientAccount &p)
{
  switch (m)
  {
  case MedicationType::Gabapentin:
    p.addCharge(50.0);
    break;
  case MedicationType::Vicodin:
    p.addCharge(70.0);
    break;
  case MedicationType::Metformin:
    p.addCharge(25.0);
    break;
  case MedicationType::Hydrocodone:
    p.addCharge(45.0);
    break;
  case MedicationType::Acetaminophen:
    p.addCharge(10.0);
    break;
  }
}