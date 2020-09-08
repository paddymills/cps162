#include "Pharmacy.h"
#include "PatientAccount.h"

void Pharmacy::addMedication(MedicationType m, PatientAccount &p)
{
  switch (m)
  {
  case GABAPENTIN:
    p.addCharge(50.0, "Gabapentin");
    break;
  case VICODIN:
    p.addCharge(70.0, "Vicodin");
    break;
  case METFORMIN:
    p.addCharge(25.0, "Metformin");
    break;
  case HYDROCODONE:
    p.addCharge(45.0, "Hydrocodone");
    break;
  case ACETAMINOPHEN:
    p.addCharge(10.0, "Acetaminophen");
    break;
  default:
    break;
  }
}