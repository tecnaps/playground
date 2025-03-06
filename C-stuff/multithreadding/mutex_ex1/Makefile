CC=gcc
CFLAGS=pthread

all: mutex

mutex: bank.o mutex_ex1.o
		$(CC) -o mutex -$(CFLAGS) bank.o mutex_ex1.o

mutex_ex1.o: mutex_ex1.c
		$(CC) -c mutex_ex1.c 

bank.o: bank.c
		$(CC) -c bank.c

clean:
		del *.o *.exe