#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patients.h"

#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
} Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Patient limit reached.\n");
        return;
    }
    Patient new_patient;
    new_patient.id = patient_count + 1; // Simple ID assignment
    printf("Enter patient name: ");
    scanf("%s", new_patient.name);
    printf("Enter patient age: ");
    scanf("%d", &new_patient.age);
    printf("Enter patient gender: ");
    scanf("%s", new_patient.gender);
    
    patients[patient_count++] = new_patient;
    printf("Patient added successfully.\n");
}

void view_patients() {
    if (patient_count == 0) {
        printf("No patients to display.\n");
        return;
    }
    printf("Patients List:\n");
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", 
               patients[i].id, patients[i].name, patients[i].age, patients[i].gender);
    }
}

Patient* search_patient(int id) {
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            return &patients[i];
        }
    }
    return NULL;
}

void update_patient(int id) {
    Patient* patient = search_patient(id);
    if (patient == NULL) {
        printf("Patient not found.\n");
        return;
    }
    printf("Updating patient: %s\n", patient->name);
    printf("Enter new name: ");
    scanf("%s", patient->name);
    printf("Enter new age: ");
    scanf("%d", &patient->age);
    printf("Enter new gender: ");
    scanf("%s", patient->gender);
    printf("Patient updated successfully.\n");
}

void delete_patient(int id) {
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;
            printf("Patient deleted successfully.\n");
            return;
        }
    }
    printf("Patient not found.\n");
}