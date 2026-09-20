#include <stdio.h>
#include <string.h>
#include "hospitalData.h"
#include "patientManagement.h"

void registerPatient(void) {
    if (totalPatients >= MAX_PATIENTS) {
        printf("Maximum patient limit reached!\n");
        return;
    }

    printf("\n--- Register New Patient ---\n");

    printf("Enter patient name: ");
    getchar();
    fgets(patientNames[totalPatients], sizeof(patientNames[totalPatients]), stdin);
    patientNames[totalPatients][strcspn(patientNames[totalPatients], "\n")] = 0;

    printf("Enter patient age: ");
    scanf("%d", &patientAges[totalPatients]);

    printf("Enter urgency level (1 = Normal, 2 = Urgent, 3 = Critical): ");
    scanf("%d", &urgencyLevels[totalPatients]);


    printf("\n--- Select Specialty Department ---\n");
    printf("1. Cardiology\n");
    printf("2. Neurology\n");
    printf("3. Orthopedics\n");
    printf("4. Pediatrics\n");
    printf("Select specialty department ID (1 to 4): ");
    scanf("%d", &specialtyIDs[totalPatients]);

    printf("Needs ward admission? (1 = Yes, 0 = No): ");
    scanf("%d", &wardAdmissions[totalPatients]);

    if (wardAdmissions[totalPatients] == 1) {

        printf("\n--- Select Ward ---\n");
        printf("1. General Ward\n");
        printf("2. ICU\n");
        printf("3. Emergency Ward\n");
        printf("4. Maternity Ward\n");
        printf("Enter ward ID (1 to 4): ");
        scanf("%d", &wardIDs[totalPatients]);

        printf("Enter number of days admitted: ");
        scanf("%d", &daysAdmitted[totalPatients]);
    } else {
        wardIDs[totalPatients] = 0;
        daysAdmitted[totalPatients] = 0;
    }

    totalPatients++;
    printf("Patient registered successfully! Total patients: %d\n", totalPatients);
}

void displayPatientQueue(void) {
    if (totalPatients == 0) {
        printf("\nNo patients registered yet!\n");
        return;
    }

    printf("\n========================================\n");
    printf("           PATIENT QUEUE LIST           \n");
    printf("========================================\n");

    for (int i = 0; i < totalPatients; i++) {
        printf("Patient %d:\n", i + 1);
        printf("  Name           : %s\n", patientNames[i]);
        printf("  Age            : %d\n", patientAges[i]);


        printf("  Urgency Level  : ");
        if (urgencyLevels[i] == 1) printf("Normal\n");
        else if (urgencyLevels[i] == 2) printf("Urgent\n");
        else if (urgencyLevels[i] == 3) printf("Critical\n");
        else printf("Unknown\n");


        printf("  Department     : ");
        switch (specialtyIDs[i]) {
            case 1: printf("Cardiology\n"); break;
            case 2: printf("Neurology\n"); break;
            case 3: printf("Orthopedics\n"); break;
            case 4: printf("Pediatrics\n"); break;
            default: printf("Unknown\n"); break;
        }


        if (wardAdmissions[i] == 1) {
            printf("  Ward Admission : Yes\n");
            printf("  Ward Type      : ");
            switch (wardIDs[i]) {
                case 1: printf("General Ward\n"); break;
                case 2: printf("ICU\n"); break;
                case 3: printf("Emergency Ward\n"); break;
                case 4: printf("Maternity Ward\n"); break;
                default: printf("Unknown\n"); break;
            }
            printf("  Days Admitted  : %d days\n", daysAdmitted[i]);
        } else {
            printf("  Ward Admission : No\n");
        }
        printf("----------------------------------------\n");
    }
}
