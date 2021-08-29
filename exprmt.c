/*************************************************************************
	> File Name: exprmt.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Thu 26 Aug 2021 07:27:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main (int argc, char* argv[]){

    write(STDOUT_FILENO, "this is a attempt!\n", 10);
    fprintf (stdout, "this is the second line!\n"); 
    return 0;
}
