#ifndef HEADERS_H
#define HEADERS_H

/************************************************************************************
**    HEADER FILES
**
************************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
/************************************************************************************
**    MACROS
**
************************************************************************************/

#define MAX_LENGTH 50
#define MAX_FILENAME 20
#define MAX_PATH_LENGTH 1000
#define SEARCH_WITH_WORD 0
#define SEARCH_WITH_FILENAME 1
#define LINE for(int i = 0;i < 100;i++) printf("-");printf("\n");

#endif 