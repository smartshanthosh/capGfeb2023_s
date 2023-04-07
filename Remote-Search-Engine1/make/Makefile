CC = gcc
CFLAGS = -Wall -c -g -std=c99 
OFLAGS = -o
BIN = ./bin/
SRC = ./src/
OBJ = ./obj/
INC = -I
HEAD = ./inc/

all:$(BIN)RSE

$(OBJ)RSE.o:$(SRC)RSE_init.c
	$(CC) $(CFLAGS) $(SRC)RSE_init.c $(INC) $(HEAD) $(OFLAGS) $(OBJ)RSE.o

$(BIN)RSE:$(OBJ)RSE.o
	$(CC) $(OFLAGS) $(BIN)RSE $(OBJ)RSE.o

clean: 
	rm $(OBJ)*.o $(BIN)*
