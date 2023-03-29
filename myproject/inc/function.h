#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structure.h"

/************************************************************************************
**    FUNCTION  DECLARATIONS
**
************************************************************************************/

int isFile(const char *);

char *extractFileName(char *);

int createFileNode(char *);

int searchInFile(char *);

int openFile(char *);

int printLinkedList(File **);

int freeMemory(File **);

int allocateMemory();

int searchLocalSystem(const char *);

int searchByWord();

//int searchByFilename();

//int openWithAbsolutePath();

/************************************************************************************
**      GLOBAL VARIABLES
**
************************************************************************************/
int search = SEARCH_WITH_FILENAME;//act as a flag to search with filename or word/string in our local system

char filename[MAX_FILENAME];//to take filename
char input[MAX_LENGTH];//to take string or word
char path[MAX_PATH_LENGTH]; //= "/home/";//Deafult path of user directory

int fileCount = 0;//file increment counter
int counter=0;

#endif
