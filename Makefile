CC = g++
CFLAGs = -c -Wall

all: main.o matrix.o
	$(CC) -o driver matrix.o main.o

matrix.o: matrix.cpp
	$(CC) $(CFLAGs) matrix.cpp

main.o: main.cpp
	$(CC) $(CFLAGs) main.cpp

clean:
	rm -f *.o
	rm -f *.gch