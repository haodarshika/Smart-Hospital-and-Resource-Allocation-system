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


    double baseFee = baseConsultationFees[specialtyIDs[index] - 1];
    double surcharge = (urgencyLevels[index] == 2) ? baseFee * 0.20 : ((urgencyLevels[index] == 3) ? baseFee * 0.50 : 0.0);
    double wardCost = (wardAdmissions[index] == 1) ? daysAdmitted[index] * dailyBedRates[wardIDs[index] - 1] : 0.0;
    double grossTotal = baseFee + surcharge + wardCost;
    double discount = (patientAges[index] < 5 || patientAges[index] > 65) ? grossTotal * 0.15 : 0.0;


    printf("\n========================================\n");
    printf("           DETAILED BILL BREAKDOWN      \n");
    printf("========================================\n");
    printf("Patient Name   : %s\n", patientNames[index]);
    printf("Patient Age    : %d\n", patientAges[index]);
    printf("Base Fee       : %.2f LKR\n", baseFee);
    printf("Urgency Fee    : %.2f LKR\n", surcharge);
    printf("Ward Cost      : %.2f LKR\n", wardCost);
    printf("Gross Total    : %.2f LKR\n", grossTotal);
    printf("Age Discount   : %.2f LKR\n", discount);
    printf("----------------------------------------\n");
    printf("Final Payable  : %.2f LKR\n", finalPayableAmounts[index]);
    printf("========================================\n");
    printf("[SUCCESS] Registration & Billing Completed!\n");
    printf("========================================\n");
}
void displaySortedPatients(void) {
    if (totalPatients <= 0) {
        printf("\n[INFO] No patients registered yet to sort!\n");
        return;
    }

    int indices[MAX_PATIENTS];
    for (int i = 0; i < totalPatients; i++) {
        indices[i] = i;
    }


    for (int i = 0; i < totalPatients - 1; i++) {
        for (int j = 0; j < totalPatients - i - 1; j++) {
            if (urgencyLevels[indices[j]] < urgencyLevels[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    printf("\n==================================================\n");
    printf("       PATIENTS SORTED BY URGENCY PRIORITY        \n");
    printf("==================================================\n");
    for (int i = 0; i < totalPatients; i++) {
        int idx = indices[i];
        printf("%d. Name: %-15s | Urgency: Level %d | Payable: %.2f LKR\n",
               i + 1, patientNames[idx], urgencyLevels[idx], finalPayableAmounts[idx]);
    }
    printf("==================================================\n");
}



    void displayPerformanceReports(void) {
    if (totalPatients <= 0) {
        printf("\n[INFO] No patients registered yet to generate reports!\n");
        return;
    }

    int normalCount = 0, urgentCount = 0, criticalCount = 0;
    double totalRevenue = 0.0;
    double totalDiscounts = 0.0;

    double maxBill = -1.0;
    int maxIndex = 0;

    for (int i = 0; i < totalPatients; i++) {
        if (urgencyLevels[i] == 1) normalCount++;
        else if (urgencyLevels[i] == 2) urgentCount++;
        else if (urgencyLevels[i] == 3) criticalCount++;

        double baseFee = baseConsultationFees[specialtyIDs[i] - 1];
        double surcharge = (urgencyLevels[i] == 2) ? baseFee * 0.20 : ((urgencyLevels[i] == 3) ? baseFee * 0.50 : 0.0);
        double wardCost = (wardAdmissions[i] == 1) ? daysAdmitted[i] * dailyBedRates[wardIDs[i] - 1] : 0.0;
        double grossTotal = baseFee + surcharge + wardCost;
        double discount = (patientAges[i] < 5 || patientAges[i] > 65) ? grossTotal * 0.15 : 0.0;

        totalRevenue += finalPayableAmounts[i];
        totalDiscounts += discount;

        if (finalPayableAmounts[i] > maxBill) {
            maxBill = finalPayableAmounts[i];
            maxIndex = i;
        }
    }

    printf("\n========================================\n");
    printf("     PERFORMANCE REPORTS & ANALYTICS    \n");
    printf("========================================\n");
    printf("1. Patient Intake Summary:\n");
    printf("   - Total Registered Patients : %d\n", totalPatients);
    printf("   - Normal (Level 1)          : %d\n", normalCount);
    printf("   - Urgent (Level 2)          : %d\n", urgentCount);
    printf("   - Critical (Level 3)        : %d\n", criticalCount);

    printf("\n2. Financial Analytics:\n");
    printf("   - Total Revenue Earned      : %.2f LKR\n", totalRevenue);
    printf("   - Total Discounts Granted   : %.2f LKR\n", totalDiscounts);

    printf("\n3. Ward Bed Occupancy Percentages:\n");
    for (int w = 0; w < TOTAL_WARDS; w++) {
        int occupiedCount = 0;
        for (int b = 0; b < totalBedCapacities[w]; b++) {
            if (bedOccupancy[w][b] == 1) {
                occupiedCount++;
            }
        }
        double occupancyPercentage = ((double)occupiedCount / totalBedCapacities[w]) * 100.0;
        printf("   - %-25s : %.1f%% (%d/%d beds)\n", wardNames[w], occupancyPercentage, occupiedCount, totalBedCapacities[w]);
    }

    printf("\n4. Highest-Paying Patient:\n");
    printf("   - Name                      : %s\n", patientNames[maxIndex]);
    printf("   - Final Bill Amount         : %.2f LKR\n", maxBill);
    printf("========================================\n");
}
