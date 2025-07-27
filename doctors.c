#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctors.h"

#define MAX_DOCTORS 100

static Doctor doctors[MAX_DOCTORS];
static int doctor_count = 0;

void add_doctor(const char *name, const char *specialization) {
    if (doctor_count < MAX_DOCTORS) {
        strcpy(doctors[doctor_count].name, name);
        strcpy(doctors[doctor_count].specialization, specialization);
        doctor_count++;
        printf("Doctor added successfully.\n");
    } else {
        printf("Cannot add more doctors. Maximum limit reached.\n");
    }
}

void view_doctors() {
    if (doctor_count == 0) {
        printf("No doctors available.\n");
        return;
    }
    printf("List of Doctors:\n");
    for (int i = 0; i < doctor_count; i++) {
        printf("Doctor ID: %d, Name: %s, Specialization: %s\n", 
               i + 1, doctors[i].name, doctors[i].specialization);
    }
}

Doctor* search_doctor(const char *name) {
    for (int i = 0; i < doctor_count; i++) {
        if (strcmp(doctors[i].name, name) == 0) {
            return &doctors[i];
        }
    }
    return NULL;
}

void update_doctor(int id, const char *name, const char *specialization) {
    if (id < 1 || id > doctor_count) {
        printf("Invalid doctor ID.\n");
        return;
    }
    strcpy(doctors[id - 1].name, name);
    strcpy(doctors[id - 1].specialization, specialization);
    printf("Doctor updated successfully.\n");
}

void delete_doctor(int id) {
    if (id < 1 || id > doctor_count) {
        printf("Invalid doctor ID.\n");
        return;
    }
    for (int i = id - 1; i < doctor_count - 1; i++) {
        doctors[i] = doctors[i + 1];
    }
    doctor_count--;
    printf("Doctor deleted successfully.\n");
}