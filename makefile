CC=gcc
OBJECTS_MAIN=main.o
OBJ=myBank.o
FLAGS= -Wall -g

all: OUT
OUT: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o OUT $(OBJECTS_MAIN) $(OBJ)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c $(OBJ)
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all
clean:
	rm -f *.o *.a *.so OUT 