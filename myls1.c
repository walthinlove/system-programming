/*************************************************************************
	> File Name: myls1.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Fri 27 Aug 2021 10:28:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main (int argc, char **argv){

    char dirName[256] = ".";
    if (argc > 1)
        strcpy (dirName, argv[1]);

    DIR *d = NULL;
    struct dirent * dir = NULL;
    struct stat statBuff = {}; 

    if ( (d = opendir(dirName)) == NULL)
        perror ("opendir");
    while ((dir = readdir (d)) != NULL){
        char type = ' ';
        printf ("%s  ", dir->d_name);
        if (stat(dir->d_name, &statBuff) < 0)
            perror ("stat");
        
        statBuff.st_mode & S_IFREG && (type = '-');
        statBuff.st_mode & S_IFDIR && (type = 'd');
        
        printf ("iNodeNumber(%ld)  mode(%d) %c\n", statBuff.st_ino, statBuff.st_mode, type);
           
    }



    return 0;
}
