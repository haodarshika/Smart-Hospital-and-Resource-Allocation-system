#ifndef HOSPITAL_DATA_H
#define HOSPITAL_DATA_H
#define TOTAL_SPECIALTIES 4
#define TOTAL_WARDS 4
#define MAX_PATIENTS 100
#define MAX_BED_CAPACITY 20



extern const char specialtyNames[TOTAL_SPECIALTIES][30];
extern const double baseConsultationFees[TOTAL_SPECIALTIES];
extern const int consultationTimes[TOTAL_SPECIALTIES];
extern const int dailyPatientCaps[TOTAL_SPECIALTIES];

extern const char wardNames[TOTAL_WARDS][30];
extern const double dailyBedRates[TOTAL_WARDS];
extern const int totalBedCapacities[TOTAL_WARDS];

extern int bedOccupancy[TOTAL_WARDS][MAX_BED_CAPACITY];

extern char patientNames[MAX_PATIENTS][50];
extern int patientAges[MAX_PATIENTS];
extern int urgencyLevels[MAX_PATIENTS];
extern int specialtyIDs[MAX_PATIENTS];
extern int wardAdmissions[MAX_PATIENTS];
extern int wardIDs[MAX_PATIENTS];
extern int bedNumbers[MAX_PATIENTS];
extern int daysAdmitted[MAX_PATIENTS];
extern double finalPayableAmounts[MAX_PATIENTS];
extern int totalPatients;
extern int specialtyQueueCounts[TOTAL_SPECIALTIES];

#endif
