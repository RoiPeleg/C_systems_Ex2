CC=gcc
OBJECTS_MAIN=main.o
OBJ=myBank.o
FLAGS= -Wall -g

all: myBankLib.so OUT
OUT: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o OUT $(OBJECTS_MAIN) ./myBankLib.so
myBankLib.so: $(OBJ) myBank.h
	$(CC) -shared -fPIC -o myBankLib.so $(OBJ) myBank.h
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c
main.o: main.c $(OBJ) 
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all
clean:
	rm -f *.o *.a *.so OUT 