/*************************************************************************
	> File Name: lseek.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Sat 28 Aug 2021 10:26:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv){

    if (argc < 1) 
        printf ("please input a file name as the command line parameter!\n");

    int fd = -1;
    if ((fd = open (argv[1], O_RDWR)) < 0)
        perror ("open");


    long int pos = -1;
    char buff[1024] = {0}; 
    if ((pos = lseek (fd, 1, SEEK_SET)) < 0)
        perror ("lseek1");
    if (read (fd, buff, 1) < 0)
        perror ("read1");
    printf ("the offset  is %ld, the character is behand the offset:\n %c\n\n\n", pos, buff[0]); 

    if (write (fd, "x", 1) < 0)
        perror ("write");
    printf ("Then if we write character to this file, the character  after possition 2 be overwritten. The read function also causes 1 offset and in default, the write function is overwritten mode:\n");
    if (lseek (fd, 0, SEEK_SET) < 0)
        perror ("lseek2");
    if (read (fd, buff, 100) < 0)
        perror ("read2");
    printf ("%s", buff);

    return 0;
}
