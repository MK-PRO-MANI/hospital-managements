typedef struct {
    int id;
    char name[100];
    char specialization[100];
    char contact[15];
} Doctor;

void addDoctor(Doctor doctor);
void viewDoctors();
Doctor* searchDoctor(int id);
void updateDoctor(int id, Doctor updatedDoctor);
void deleteDoctor(int id);