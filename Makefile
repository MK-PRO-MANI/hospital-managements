CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/main.c src/patients.c src/doctors.c src/appointments.c
OBJ = $(SRC:.c=.o)
EXEC = hospital_management_system

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean