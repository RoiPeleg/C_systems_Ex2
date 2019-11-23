CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS= -Wall -g

all: OUT
OUT: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) 
myBank.o: myBank.c 
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all

clean:
	rm -f *.o *.a *.so OUT 