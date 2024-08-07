#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

extern int errno;

int main(){
    
    int fd = open("foo.txt",O_RDONLY | O_CREAT);

    printf("fd = %d\n",fd);

    if(fd ==-1){
        printf("Error Number %d\n", errno);

        perror("Program");
    }

    return 0;
}