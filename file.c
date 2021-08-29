/*************************************************************************
	> File Name: file.c
	> Author:Junsen Wang 
	> Mail: 
	> Created Time: Wed 25 Aug 2021 04:12:38 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv){
    int fd, fd1;
    if (argc < 2) {
        fprintf (stderr, "Usage : You need to pass a file name to main function. Paramter argv[0] : %s is not a file name.\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0){
        perror ("open"); 
        fprintf (stderr, "%d\n", errno);
        exit(1);
    }
    if ((fd1 = open(argv[2], O_RDWR | O_CREAT | O_APPEND, 0000000000000777)) < 0){ 
        perror ("open1"); 
        fprintf (stderr, "%d\n", errno);
        exit(1);
    }
    char buff[1024] = {0}; 
    ssize_t num, num1;
    while ((num = read(fd, buff, sizeof(buff))) > 0){
        printf ("%s\n", buff);
        if ((num1 = write (fd1, buff, num)) < 0) {
            perror ("write");
        }
    }
    perror ("read");
    close(fd);
    close(fd1);

    return 0;
}
