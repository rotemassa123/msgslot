#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define IOCTL_COMMAND_ID 8

int main(int argc, char *argv[]){
    int fd, channel_number, i;

    if(argc != 4){ perror("wrong amout of arguments"); exit(1); }

    if((fd = open(argv[1], O_RDWR)) < 0) { perror("could not open file"); }
    channel_number = atoi(argv[2]);

    ioctl(fd, IOCTL_COMMAND_ID, channel_number);
    if(write(fd, argv[3], strlen(argv[3])) < 0) { perror("cannot write to device");}

    if(close(fd) < 0) { perror("cannot close"); }
    exit(0);
}