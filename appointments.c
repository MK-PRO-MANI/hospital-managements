#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "appointments.h"

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char patientName[100];
    char doctorName[100];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

static Appointment appointments[MAX_APPOINTMENTS];
static int appointmentCount = 0;

void addAppointment(int id, const char *patientName, const char *doctorName, const char *date, const char *time) {
    if (appointmentCount < MAX_APPOINTMENTS) {
        appointments[appointmentCount].id = id;
        strncpy(appointments[appointmentCount].patientName, patientName, sizeof(appointments[appointmentCount].patientName) - 1);
        strncpy(appointments[appointmentCount].doctorName, doctorName, sizeof(appointments[appointmentCount].doctorName) - 1);
        strncpy(appointments[appointmentCount].date, date, sizeof(appointments[appointmentCount].date) - 1);
        strncpy(appointments[appointmentCount].time, time, sizeof(appointments[appointmentCount].time) - 1);
        appointmentCount++;
        printf("Appointment added successfully.\n");
    } else {
        printf("Appointment limit reached. Cannot add more appointments.\n");
    }
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments available.\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("ID: %d, Patient: %s, Doctor: %s, Date: %s, Time: %s\n",
               appointments[i].id, appointments[i].patientName, appointments[i].doctorName,
               appointments[i].date, appointments[i].time);
    }
}

Appointment* searchAppointment(int id) {
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id) {
            return &appointments[i];
        }
    }
    return NULL;
}

void updateAppointment(int id, const char *patientName, const char *doctorName, const char *date, const char *time) {
    Appointment *appointment = searchAppointment(id);
    if (appointment) {
        strncpy(appointment->patientName, patientName, sizeof(appointment->patientName) - 1);
        strncpy(appointment->doctorName, doctorName, sizeof(appointment->doctorName) - 1);
        strncpy(appointment->date, date, sizeof(appointment->date) - 1);
        strncpy(appointment->time, time, sizeof(appointment->time) - 1);
        printf("Appointment updated successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

void cancelAppointment(int id) {
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id) {
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            printf("Appointment canceled successfully.\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}

void saveAppointmentsToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < appointmentCount; i++) {
            fprintf(file, "%d,%s,%s,%s,%s\n", appointments[i].id, appointments[i].patientName,
                    appointments[i].doctorName, appointments[i].date, appointments[i].time);
        }
        fclose(file);
        printf("Appointments saved to file successfully.\n");
    } else {
        printf("Error opening file for saving appointments.\n");
    }
}