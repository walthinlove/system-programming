/*************************************************************************
	> File Name: main_arg.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 05:04:42 PM CST
 ************************************************************************/

#include<stdio.h>


/**
 
 
    the main function signature:
    the first parameter is an int number. It represents the number of parameter passed to main.
    The second parameter is an char* array. They are parameters passed to main function.
 

 
 * */


int main ( const char* arg[], int c){

    printf ("the argc = %d\n", c);
    for (int i = 0; i < 90; i++)
        printf ("argv[%d]: %s\n", i, arg[i]);
    return 0;
}
