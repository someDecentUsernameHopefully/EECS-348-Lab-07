CC = g++
CFLAGs = -c -Wall
FNAME = matrix-template-1

all: $(FNAME).o
	$(CC) -o driver $(FNAME).o

$(FNAME).o: $(FNAME).cpp
	$(CC) $(CFLAGs) $(FNAME).cpp

clean:
	rm -f *.o
	rm -f *.gch