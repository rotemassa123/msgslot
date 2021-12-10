#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>

#define IOCTL_COMMAND_ID 8


int main(int argc, char *argv[]){
    int fd, channel_number;
    char buf[128];

    if(argc != 3){ perror("wrong amout of arguments"); exit(1); }

    if((fd = open(argv[1], O_RDWR)) < 0) { perror("could not open file"); }

    channel_number = atoi(argv[2]);

    ioctl( fd, IOCTL_COMMAND_ID, channel_number);
    if(read(fd, buf, 128) < 0) { perror("reading failed"); }
    write(1, buf, )

    if(close(fd) < 0) { perror("error closinggg"); };
    return 0;
}