#include<stdio.h>
#include "hospitalData.h"
#include "patientManagement.h"
void displayPerformanceReports(int totalRegisteredPatients);
int main(void ){
    printf("Smart Hospital System Intialized\n");
    int totalRegisteredPatients=1;

    registerPatient();
    displayPerformanceReports(totalRegisteredPatients);
    return 0;

}


