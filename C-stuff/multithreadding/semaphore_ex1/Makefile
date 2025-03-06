CC=gcc
CFLAGS=pthread

all: semaphore

semaphore: semaphore_ex1.o
		$(CC) -o semaphore -$(CFLAGS) semaphore_ex1.o

semaphore_ex1.o: semaphore_ex1.c
		$(CC) -c semaphore_ex1.c

clean:
	del *.o *.exe