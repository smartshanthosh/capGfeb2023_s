CC = gcc
CFLAGS = -Wall -c -g  
LDFLAGS = -o

BIN = ./bin
SRC = ./src
OBJ = ./obj
INC = ./inc/

IFLAGS = -I $(INC)

all:RSE


RSE:$(OBJ)/RSE_init.o $(OBJ)/function_definition.o
	$(CC) $(LDFLAGS) $(BIN)/RSE $(OBJ)/RSE_init.o $(OBJ)/function_definition.o

$(OBJ)/RSE_init.o:$(SRC)/RSE_init.c
	$(CC) $(CFLAGS) $(SRC)/RSE_init.c $(IFLAGS)
	mv *.o $(OBJ)

$(OBJ)/function_definition.o:$(SRC)/function_definition.c
	$(CC) $(CFLAGS) $(SRC)/function_definition.c $(IFLAGS)
	mv *.o $(OBJ)

clean: 
	rm -f $(OBJ)/*
	rm -f $(BIN)/*
	@echo "Cleaning Done...!!"
