CC = g++
CFLAGS = -Wall -Werror

all: myprogram

myprogram: main.o
	$(CC) $(CFLAGS) -o myprogram main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f myprogram *.o

.PHONY: clean
