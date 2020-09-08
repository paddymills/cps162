#include <iostream>
#include <string>

#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"

using namespace std;

int main()
{

  // init objects
  PatientAccount patient;
  Pharmacy pharmacy;
  Surgery surgery;

  surgery.addSurgery(GASTRIC_BYPASS, patient);
  pharmacy.addMedication(GABAPENTIN, patient);
  surgery.addSurgery(HEPATIC_RESECTION, patient);
  pharmacy.addMedication(VICODIN, patient);
  pharmacy.addMedication(ACETAMINOPHEN, patient);
  patient.addDays(3);

  patient.displaySummary();

  return 0;
}