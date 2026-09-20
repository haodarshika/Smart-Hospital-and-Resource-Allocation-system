#include "hospitalData.h"

const char specialtyNames[4][30] = {"General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology"};
const double baseConsultationFees[4] = {1500.00, 2500.00, 4500.00, 5000.00};
const int consultationTimes[4] = {15, 20, 30, 30};
const int dailyPatientCaps[4] = {30, 20, 12, 10};

const char wardNames[4][30] = {"General Ward", "Paediatric Ward", "Surgical Ward", "ICU (Intensive Care Unit)"};
const double dailyBedRates[4] = {3000.00, 6000.00, 12000.00, 25000.00};
const int totalBedCapacities[4] = {20, 10, 10, 5};

int bedOccupancy[4][20] = {0};


char patientNames[MAX_PATIENTS][50];
int patientAges[MAX_PATIENTS];
int urgencyLevels[MAX_PATIENTS];
int specialtyIDs[MAX_PATIENTS];
int wardAdmissions[MAX_PATIENTS];
int wardIDs[MAX_PATIENTS];
int bedNumbers[MAX_PATIENTS];
int daysAdmitted[MAX_PATIENTS];
double finalPayableAmounts[MAX_PATIENTS];
int totalPatients = 0;
int specialtyQueueCounts[4] = {0};
