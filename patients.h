#ifndef PATIENTS_H
#define PATIENTS_H

typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char contact[15];
} Patient;

void addPatient(Patient patient);
void viewPatients();
Patient* searchPatient(int id);
void updatePatient(int id, Patient updatedPatient);
void deletePatient(int id);

#endif // PATIENTS_H