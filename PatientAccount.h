class PatientAccount
{
private:
  int daysSpentInHospital;
  double charges;

public:
  void addDays(int);
  void addCharge(double);
  int getDaysSentInHospital();
  double getCharges();
  void addSurgery();
  void addMedication();
};
