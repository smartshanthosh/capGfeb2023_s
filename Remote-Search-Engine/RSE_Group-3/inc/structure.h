#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "headers.h"

/************************************************************************************
**     STRUCTURE NAME     :     File
**
**    DESCRIPTION        :      structure to create node for the File Linked List  
**
**     RETURNS           :      NOT APPLIED
**
**
************************************************************************************/

typedef struct struct_File{
    char f_name[MAX_LENGTH];
    char f_path[MAX_PATH_LENGTH];
    struct struct_File* next;
}File;

File *head = NULL;
File *curr = NULL;
#endif 
