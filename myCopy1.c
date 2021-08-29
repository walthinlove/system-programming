/*************************************************************************
	> File Name: myCopy1.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Thu 26 Aug 2021 04:14:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char** argv){
    int opt;
    /*
        char *rname, *wname;
        This form of variable can only be used to store pointer, not a char string. 
    */

    char  rname[256], wname[256];
    while ((opt = getopt(argc, argv, "r:w:")) != -1){
        if (opt == 'w') 
            strcpy(wname, optarg);
        else
            strcpy(rname, optarg);
    }
    
    perror("getopt");
    
    
    FILE* f1, *f2;
    f1 = fopen (rname, "r");
    perror ("rname");
    f2 = fopen (wname, "a");
    perror ("wname");
    
    char buff[1025];
    int num = 0;
    
    while ((num = fread (buff, 1, sizeof (buff), f1)) > 0) {
        fprintf (stdout,"%s", buff);
       if (fwrite (buff, 1, num, f2) < 0)
            perror ("fwrite");
    }
    
    perror ("fread");

    fclose (f1);
    fclose (f2);

    return 0;
}
