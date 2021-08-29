/*************************************************************************
	> File Name: myls.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Fri 27 Aug 2021 09:08:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main (int argc, char** argv){
    char dirName[256] = ".";
    
    if (argc > 1) 
        strcpy (dirName, argv[1]);


    DIR * d1 = NULL;
    if ((d1 = opendir(dirName)) == NULL)
        perror("opendir");

    struct dirent * dir = NULL;

    dir = readdir (d1);
        printf ("%s  ", dir->d_name);
    /* 
    while ((dir = readdir (d1)) != NULL){
        printf ("%s  ", dir->d_name);
    }
    printf ("\n");
   */ 
    closedir(d1);
    return 0;
}
