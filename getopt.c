/*************************************************************************
	> File Name: getopt.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Mon 23 Aug 2021 02:47:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>





/*
        ./a.out -a113  000sad  -bsad -c 
*/

int main(int argc, char* const argv[]){
    
    printf ("Before the getopt() function, the argv list is :\n");
    for (int i = 0; argv[i]; i++)
        printf ("%s\n", argv[i]);
    printf ("\n\n\n\n");

    //opterr = 0;
    /*
        if you don't print the error information of getopt. You can set opterr =0.
        This statement should be placed before the getopt() function, otherwise it does not work.
    */
    char c;
    //while( (c = getopt(argc, argv, "-ab:c::")) != -1) {
    while( (c = getopt(argc, argv, "ab:c::")) != -1) {
        printf ("the current opttion is %c, parameters are %s, ", c, optarg);
    
        printf ("the next option is at position %d \n", optind);
    }

    //opterr = 0;
    
    printf ("after the getopt() function, the argv list is :\n");
    for (int i = 0; argv[i]; i++)
        printf ("%s\n", argv[i]);

    printf ("optopt = %d, optopt = %c\n", optopt, optopt);
    return 0;
}
