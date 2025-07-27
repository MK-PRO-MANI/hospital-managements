# Hospital Management System

This project implements a hospital management system that allows for the management of patients, doctors, and appointments. The system provides functionalities to add, view, search, update, and delete records for each category.

## Features

- **Patient Management**: Add, view, search, update, and delete patient records.
- **Doctor Management**: Add, view, search, update, and delete doctor records.
- **Appointment Management**: Schedule, view, search, and cancel appointments.

## Project Structure

```
hospital-management-system
├── src
│   ├── main.c          # Entry point of the application
│   ├── patients.c      # Patient management functions
│   ├── patients.h      # Patient structure and prototypes
│   ├── doctors.c       # Doctor management functions
│   ├── doctors.h       # Doctor structure and prototypes
│   ├── appointments.c   # Appointment management functions
│   ├── appointments.h   # Appointment structure and prototypes
├── include
│   ├── patients.h      # External access to patient functions
│   ├── doctors.h       # External access to doctor functions
│   └── appointments.h   # External access to appointment functions
├── Makefile             # Build instructions
└── README.md            # Project documentation
```

## Compilation

To compile the project, navigate to the project directory and run:

```
make
```

This will generate the executable for the hospital management system.

## Running the Application

After compiling, you can run the application using:

```
./hospital_management_system
```

Follow the on-screen instructions to manage patients, doctors, and appointments.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and contributions are welcome!