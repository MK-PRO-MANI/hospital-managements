#include <stdio.h>
#include <stdlib.h>
#include "patients.h"
#include "doctors.h"
#include "appointments.h"

void displayMenu() {
    printf("Hospital Management System\n");
    printf("1. Manage Patients\n");
    printf("2. Manage Doctors\n");
    printf("3. Manage Appointments\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                managePatients();
                break;
            case 2:
                manageDoctors();
                break;
            case 3:
                manageAppointments();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}