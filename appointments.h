#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H

typedef struct {
    int id;
    int patientId;
    int doctorId;
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    char status[20]; // e.g., Scheduled, Cancelled, Completed
} Appointment;

// Function prototypes
void addAppointment(Appointment appointment);
void viewAppointments();
Appointment* searchAppointment(int id);
void updateAppointment(int id, Appointment updatedAppointment);
void deleteAppointment(int id);

#endif // APPOINTMENTS_H