#ifndef HOSPITAL_DATA_H
#define HOSPITAL_DATA_H
#define TOTAL_SPECIALTIES 4
#define TOTAL_WARDS 4
#define MAX_PATIENTS 100
#define MAX_BED_CAPACITY 20



extern const char specialtyNames[TOTAL_SPECIALTIES][30];
extern const double baseConsultationFees[TOTAL_SPECIALTIES];
extern const int  consultationTimes[TOTAL_SPECIALTIES];

#endif
