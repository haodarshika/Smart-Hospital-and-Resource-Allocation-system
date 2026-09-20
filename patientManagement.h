#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

#define MAX_PATIENTS 100


  extern char patientNames[MAX_PATIENTS][50];
 extern int patientAges[MAX_PATIENTS];
extern int urgencyLevels[MAX_PATIENTS];
extern int specialtyIDs[MAX_PATIENTS];
 extern int wardAdmissions[MAX_PATIENTS];
 extern int wardIDs[MAX_PATIENTS];
 extern int daysAdmitted [MAX_PATIENTS];
 extern int totalPatients;
void registerPatient();
void displayPatientQueue();

#endif


