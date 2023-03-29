CC = gcc
CFLAGS = -Wall -c -g -std=c99 
OFLAGS = -o
BIN = ./bin/
SRC = ./src/
OBJ = ./obj/
INC = -I
HEAD = ./inc/

all:$(BIN)LSE

$(OBJ)LSE.o:$(SRC)main.c
	$(CC) $(CFLAGS) $(SRC)main.c $(INC) $(HEAD) $(OFLAGS) $(OBJ)LSE.o

$(BIN)LSE:$(OBJ)LSE.o
	$(CC) $(OFLAGS) $(BIN)LSE $(OBJ)LSE.o

clean: 
	rm $(OBJ)*.o $(BIN)*
