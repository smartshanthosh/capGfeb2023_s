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

int searchByFilename();

int openWithAbsolutePath();

/************************************************************************************
**      GLOBAL VARIABLES
**
************************************************************************************/
int search = SEARCH_WITH_FILENAME;

char filename[MAX_FILENAME];
char input[MAX_LENGTH];
char path[MAX_PATH_LENGTH];
char pathcopy[MAX_LENGTH];

int fileCount = 0;
int counter=0;

#endif 
