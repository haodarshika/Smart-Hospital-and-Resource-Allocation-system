#include<stdio.h>
#include "hospitalData.h"
#include "patientManagement.h"



int main(void) {
    int choice;
    printf("Smart Hospital System Initialized\n");

    do {
        printf("\n========================================\n");
        printf("       SMART HOSPITAL MAIN MENU         \n");
        printf("========================================\n");
        printf("1. Register New Patient & Calculate Bill\n");
        printf("2. View Patients Sorted by Urgency (R4) \n");
        printf("3. View Performance Reports & Analytics (R6)\n");
        printf("4. Exit System                          \n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                displaySortedPatients();
                break;
            case 3:
                displayPerformanceReports();
                break;
            case 4:
                printf("\nExiting system. Thank you!\n");
                break;
            default:
                printf("\n[ERROR] Invalid choice! Please enter 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}


