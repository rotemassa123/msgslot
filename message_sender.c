#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define IOCTL_COMMAND_ID 8

int main(int argc, char *argv[]){
    int fd, channel_number, i;

    if(argc != 4){ return -1; }

    if((fd = open(argv[1], O_RDWR)) < 0) { perror("could not open file"); }
    channel_number = atoi(argv[2]);

    ioctl( fd, IOCTL_COMMAND_ID, channel_number);

    for(i = 0; i < strlen(argv[3]) - 1; i++)
        write(fd, &argv[3][i], 1);

    close(fd);

    return 0;
}