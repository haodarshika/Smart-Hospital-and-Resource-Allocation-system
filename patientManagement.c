#include <stdio.h>
#include "hospitalData.h"
#include "patientManagement.h"


extern int specialtyQueueCounts[4];
extern const int consultationTimes[4];
extern const double baseConsultationFees[4];
extern int urgencyLevels[];
extern int wardAdmissions[];
extern int wardIDs[];
extern int daysAdmitted[];
extern const double dailyBedRates[4];
extern int patientAges[];
extern double finalPayableAmounts[];
extern int specialtyIDs[];
extern char patientNames[100][50];


void calculatePatientBill(int index) {
    double waitTime = specialtyQueueCounts[specialtyIDs[index] - 1] * consultationTimes[specialtyIDs[index] - 1];
    (void)waitTime;
    specialtyQueueCounts[specialtyIDs[index] - 1]++;

    double baseFee = baseConsultationFees[specialtyIDs[index] - 1];
    double surcharge = 0.0;
    if (urgencyLevels[index] == 2) {
        surcharge = baseFee * 0.20;
    } else if (urgencyLevels[index] == 3) {
        surcharge = baseFee * 0.50;
    }

    double wardCost = 0.0;
    if (wardAdmissions[index] == 1) {
        wardCost = daysAdmitted[index] * dailyBedRates[wardIDs[index] - 1];
    }

    double grossTotal = baseFee + surcharge + wardCost;

    double discount = 0.0;
    if (patientAges[index] < 5 || patientAges[index] > 65) {
        discount = grossTotal * 0.15;
    }

    finalPayableAmounts[index] = grossTotal - discount;
}

void registerPatient() {
    int index = 0;

    printf("\n========================================\n");
    printf("         SMART HOSPITAL SYSTEM          \n");
    printf("          PATIENT REGISTRATION          \n");
    printf("========================================\n");

    printf("Enter Patient Name: ");
    scanf(" %[^\n]%*c", patientNames[index]);

    printf("Enter Patient Age: ");
    scanf("%d", &patientAges[index]);

    printf("\n--- Urgency Levels ---\n");
    printf("1. Normal\n");
    printf("2. Urgent\n");
    printf("3. Critical\n");
    printf("Enter Urgency Level (1-3): ");
    scanf("%d", &urgencyLevels[index]);

    printf("\n--- Available Specialty Departments ---\n");
    printf("1. Cardiology\n");
    printf("2. Neurology\n");
    printf("3. Orthopedics\n");
    printf("4. Pediatrics\n");
    printf("Select Specialty ID (1 to 4): ");
    scanf("%d", &specialtyIDs[index]);

    printf("\nIs Patient Admitted to a Ward? (1 = Yes, 0 = No): ");
    scanf("%d", &wardAdmissions[index]);

    if (wardAdmissions[index] == 1) {
        printf("\n--- Available Wards ---\n");
        printf("1. General Ward\n");
        printf("2. Private Ward\n");
        printf("3. ICU\n");
        printf("4. Maternity Ward\n");
        printf("Select Ward ID (1 to 4): ");
        scanf("%d", &wardIDs[index]);

        printf("Enter Days Admitted: ");
        scanf("%d", &daysAdmitted[index]);
    } else {
        wardIDs[index] = 0;
        daysAdmitted[index] = 0;
    }

    calculatePatientBill(index);
    printf("\n[SUCCESS] Patient registered and bill calculated successfully!\n");
    printf("========================================\n");
}
