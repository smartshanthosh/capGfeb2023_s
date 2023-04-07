#include <function.h>
/************************************************************************************
**     FUNCTION NAME     :     isFile
**
**    DESCRIPTION        :    function to find whether given path is a directory or  
**                            a file
**
**     RETURNS           :    return an integer (0=directory,1=file ,-1 =elsewise) 
**     
**     
************************************************************************************/

int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return 0;
    }
    if(errno == ENOTDIR)
    {
     return 1;
    }

    return -1;
}

/************************************************************************************
**     FUNCTION NAME     :     extractFileName
**
**    DESCRIPTION        :    function to extract the File name from given path
**
**     RETURNS           :    return a pointer to char 
**
**************************************************************************************/
char *extractFileName(char * path){
    char *token = strtok(path, "/");
    char * prev = (char * ) malloc(MAX_LENGTH * sizeof(char));
    if(prev==NULL)
    {
        return "Memory Allocation Failed!!\n";
    }

    while(token != NULL){
        strcpy(prev, token);
        token = strtok(NULL, "/");
    }

    return prev;
}

/************************************************************************************
**     FUNCTION NAME     :     createFileNode
**
**    DESCRIPTION        :    function to create a node in a Linked List
**
**     RETURNS           :    returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int createFileNode(char *path){
    
    char copyPath[MAX_PATH_LENGTH];
    strcpy(copyPath, path);

    if(head == NULL){
        head = (File *) malloc(sizeof(File));
        if(head==NULL)
        {
            fprintf(stderr,"%s","Memory Allocation Failed...!!\n");
            return EXIT_FAILURE;
        }
        strcpy(head->f_path, copyPath);
        char * str = extractFileName(path);
        strcpy(head->f_name, str);
        counter=0;
        printf("File %d --> %s path:[%s]\n",counter, head->f_name, head->f_path);
        free(str); 
        head->next = NULL;
        curr = head;       
    }else{
        curr->next = (File *) malloc(sizeof(File));
        if(curr->next==NULL)
        {
            fprintf(stderr,"%s","Memory Allocation Failed...!!\n");
            return EXIT_FAILURE;
        }
        curr = curr->next;
        strcpy(curr->f_path, copyPath);
        char * str = extractFileName(path);
        strcpy(curr->f_name, str);
        counter+=1;
        printf("File %d --> %s path:[%s]\n",counter, curr->f_name, curr->f_path);
        free(str);
        curr->next = NULL;
    }
    return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME     :     searchInFile
**
**    DESCRIPTION        :      it takes a single argument a pointer to char (path of file )
**                              opens the file and check whether givem search argument(string)
**                              is present inside the file. If present create a file node add it
**                              to the Linked List and increment file counter else skip the file. 
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
*************************************************************************************/

int searchInFile(char *path){
    FILE *f = fopen(path, "r");
    if( access( path, F_OK ) != 0) {
        //File doesn't have read permission
        return EXIT_FAILURE;
    }
    if(f == NULL){
        return EXIT_FAILURE;
    }
    char temp[MAX_LENGTH];
    while (fgets(temp, MAX_LENGTH, f) != NULL)
    {
        if(strstr(temp, input) != NULL){ //Match found
            fileCount++;
            int res = createFileNode(path);
            if(res == EXIT_FAILURE){
                return EXIT_FAILURE;
            }
            break;
        }
    }   
    if(f){
        fclose(f);
    }
    return EXIT_SUCCESS;
    
}

/************************************************************************************
**     FUNCTION NAME     :      openFile
**
**    DESCRIPTION        :      it is a utility function which takes the file path and prints its 
**                              contents on the console
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int openFile(char * fpath){
    FILE * fptr = fopen(fpath, "r");
    if(fptr == NULL){
        fprintf(stderr,"%s","File not Found...!!\n");
        if(fptr){
            fclose(fptr);
        }
        return EXIT_FAILURE;
    }
    if(isFile(fpath) == 0){
        fprintf(stderr,"%s","Given path is a directory...!!\n");

        if(fptr){
            fclose(fptr);
        }
		
        return EXIT_FAILURE;
    }
    
    printf("File opened!\n\n");
    LINE
    char c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    printf("\n");

    fclose(fptr);
    return EXIT_SUCCESS;
}

/************************************************************************************
**    FUNCTION NAME     :      printLinkedList
**
**    DESCRIPTION        :     prints the Link List  
**
**     RETURNS           :    returns EXIT_SUCCESS/EXIT_FAILURE
**
**
************************************************************************************/

int printLinkedList(File **ptr){
    if(fileCount == 0 || ptr==NULL){
        fprintf(stderr,"%s","No files Found...!!\n");
        return EXIT_FAILURE;
    }

    int flag = 0;
    char mychoice[MAX_LENGTH];
    LINE
    printf("do you want to open any file!!(y/n)\n");
    scanf("%s",mychoice);
    getchar();
    if(mychoice[0]=='y'||mychoice[0]=='Y')
    {
    
    do
    {   
        printf("\n%d file(s) found\n\n", fileCount);
        LINE
            
            printf("Select the file number which you want to open\n");
            char option[MAX_LENGTH];
            int myflag = 0;
            int num = 0;
            do
            {
                printf("Please enter file index number\n");
                scanf("%s", option);
                getchar();
                myflag=0;
                num=0;
                for(int i=0;option[i]!='\0';i++)
                {
                    if(isdigit(option[i])==0)
                    {
                        myflag=1;
                        break;
                    }
                    else
                    {
                        num=num*10+(option[i]-48);
                    }
                }
                if(myflag==1||num<0||num>fileCount-1)
                    fprintf(stderr,"%s","File index does not exist...!!\n");


            } while (num < 0 || num > fileCount-1||myflag==1);

            File *tmp = *(ptr+num);
            LINE
            openFile(tmp->f_path);
            num= -1;
            LINE
            printf("Do you want to open other file?(y/n)");
            char ch[MAX_LENGTH];
            scanf("%s", ch);
            getchar();
            if(strlen(ch) > 1){
                ch[0] = '5';
            }

            switch (ch[0])
            {
            case 'y':
            case 'Y':
                flag = 0;
                break;
            case 'N':
            case 'n':
                flag = 1;
                break;
            default:
                fprintf(stderr,"%s","Invalid Choice...!!\n");
                flag = 1;
                break;
            }  
        
    } while (flag == 0); 
    }
    else if((mychoice[0]!='n' && mychoice[0]!='N' )||strlen(mychoice)>1)
    {
        fprintf(stderr,"%s","Invalid choice!!\n");
    }

    return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME     :      freeMemory
**
**    DESCRIPTION        :      free all the memory created dynamically till now  
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int freeMemory(File **ptr){

    if(ptr == NULL){
        return EXIT_SUCCESS;
    }

    for(int i = 0; i<fileCount; i++){
        if(*(ptr+i) != NULL){
            free(*(ptr+i));
            *(ptr+i)=NULL;
        }
    }
    head = NULL;
    curr = NULL;
    free(ptr);
    ptr=NULL;
    if(ptr != NULL){
        return EXIT_FAILURE;
    }else{
        return EXIT_SUCCESS;
    }
}

/************************************************************************************
**     FUNCTION NAME     :      allocateMemory
**
**    DESCRIPTION        :      creates a pointer to an array of pointers of File structure  
**                              and stores the pointer to every node for quick access and 
**                              calls the function printLinkedList 
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE 
**
************************************************************************************/

int allocateMemory(){
    File **ptr = (File **) malloc(fileCount * sizeof(File *));

    if(ptr == NULL){

        return EXIT_FAILURE;
    }

    if(head != NULL){
        File * tmp = head;
        int c = 0;
        while(tmp != NULL){
            *(ptr + c) = tmp;
            tmp = tmp->next;
            c++;
        }
    }

    printLinkedList(ptr);
    int res = freeMemory(ptr);
    if(res == EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME      :      searchLocalSytem
**
**     DESCRIPTION        :      search the system recursively in all the directories for 
**                              the given path
**
**     RETURNS            :      returns EXIT_SUCCESS/EXIT_FAILURE.
**
**     
************************************************************************************/

int searchLocalSystem(const char * path){
    
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(strcmp(dir->d_name, ".") == 0 ||
                 strcmp(dir->d_name, "..") == 0 ||
                    dir->d_name[0] == '.'){
                continue;
            }
            char *currPath = (char *) calloc(1000, sizeof(char));
            strcat(currPath, path);
            strcat(currPath, dir->d_name);
            strcat(currPath, "/");
            if(isFile(currPath) == 0){
                searchLocalSystem(currPath); // Recursive call to the new appended path
            }else{
                if(strstr(dir->d_name,".txt")==NULL
                            &&strstr(dir->d_name,".c")==NULL   
                                &&strstr(dir->d_name,".h")==NULL)
                {
                    free(currPath);
                    continue;
                }
                currPath[strlen(currPath) - 1] = '\0';
                if(search == SEARCH_WITH_WORD){
                    int res = searchInFile(currPath);
                    if(res == EXIT_FAILURE){
                        free(currPath);
                        return EXIT_FAILURE;
                    }
                }else{
                    if(strcmp(dir->d_name, filename) == 0 || strstr(dir->d_name,filename)!=NULL){
                        fileCount++;
                        int res = createFileNode(currPath);
                        if(res == EXIT_FAILURE){
                            free(currPath);
                            return EXIT_FAILURE;
                        }
                    }                    
                }
            }
            free(currPath);
        }
        closedir(d);
    }
    else    
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME     :      searchByWord
**
**    DESCRIPTION        :      function to get the search string and call the file system(searchLocalSystem)   
**                              to find the given word
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int searchByWord(){
    
    search = SEARCH_WITH_WORD;
    int flag = 0;

    printf("Enter search string/word:\n");
    fgets(input,MAX_LENGTH, stdin);
    input[strlen(input) - 1] = '\0';
    LINE
    printf("Do you want to search at any specific locations?(y/n)\n");
    
    char c[MAX_LENGTH];
    fgets(c, MAX_LENGTH, stdin);
    c[strlen(c) - 1] = '\0';
    
    if(strlen(c) > 1){
        c[0] = 'k';
    }  


    char userPath[MAX_LENGTH];
    switch (c[0])
    {
        case 'y':
        case 'Y':
            flag = 1;
            printf("Please provide path\n");
            printf("%s", path);
			strcpy(pathcopy,path);
            fgets(userPath, 50, stdin);
            userPath[strlen(userPath) - 1] = '\0';
            strcat(pathcopy, userPath);
            strcat(pathcopy, "/");

            LINE
            printf("Searching..\n");
            searchLocalSystem(path);
            break;
        
        case 'n':
        case 'N':
            printf("Searching..\n");
            printf("%s\n", path);
            flag = 1;
            searchLocalSystem(path);
            break;
        
        default:
            fprintf(stderr,"%s","Wrong Choice...!!\n");
            break;
    }
    
    if(flag == 1){
        int res = allocateMemory();
        if(res == EXIT_FAILURE){
            fileCount = 0;
            fprintf(stderr,"%s","Cannot list files.\n");
        return EXIT_FAILURE;
        }
    }
    
    fileCount = 0;
    
    return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME     :      searchFileName
**
**    DESCRIPTION        :      function to get the search string(file Name) and call the file    
**                              system(searchLocalSystem) to find the given file name
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int searchByFilename(){
    search=SEARCH_WITH_FILENAME;
    int flag = 0;
    printf("Enter filename to be searched:\n");
    fgets(filename,MAX_LENGTH, stdin);
    printf("Searching %s\n", filename);
    LINE
    filename[strlen(filename) - 1] = '\0';
    
    printf("Do you want to provide any absolute directory path?(y/n)\n");
    
    char userPath[MAX_LENGTH];
    char c[10];
    fgets(c, 10, stdin);
    c[strlen(c) - 1]='\0';

    if(strlen(c) > 1){
        c[0] = 'k';
    }  

    switch (c[0])
    {
        case 'y':
        case 'Y':
            flag = 1;
            printf("Enter absolute path:\n");
            printf("$:%s", path);
			strcpy(pathcopy,path);
            fgets(userPath, MAX_LENGTH, stdin);
            userPath[strlen(userPath)-1] = '\0';
            strcat(pathcopy, userPath);
            strcat(pathcopy, "/");
            printf("\n");
            LINE
            searchLocalSystem(path);

            break;

        case 'n':
        case 'N':
            flag = 1;
            searchLocalSystem(path);
            break;
        default:
             fprintf(stderr,"%s","Innvalid Choice.\n");
            break;
    }    

    if(flag == 1){
        int res = allocateMemory();
        if(res == EXIT_FAILURE){
            fprintf(stderr,"%s","Cannot list files.\n");
            fileCount = 0;

            return EXIT_FAILURE;
        }
    }
    fileCount = 0;

   return EXIT_SUCCESS;
}

/************************************************************************************
**     FUNCTION NAME     :      openWithAbsolutePath
**
**    DESCRIPTION        :      function to get the absolute file path and displays all the 
**                              contents of the given file path using openFile function 
**
**     RETURNS           :      returns EXIT_SUCCESS/EXIT_FAILURE
**
************************************************************************************/

int openWithAbsolutePath(){
    printf("Enter abolute path to the file:\n");
    printf("$:%s",path);
    char pathInput[MAX_LENGTH];

    fgets(pathInput, MAX_LENGTH, stdin);
    pathInput[strlen(pathInput) - 1] = '\0';
	
	strcpy(pathcopy,path);
    strcat(pathcopy, pathInput);
    
	openFile(pathcopy);
    return EXIT_SUCCESS;

}
