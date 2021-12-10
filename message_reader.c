#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define IOCTL_COMMAND_ID 8


int main(int argc, char *argv[]){
    int fd, channel_number, msg_len;
    char buf[128];

    if(argc != 3){ errno = EINVAL; perror("wrong amout of arguments"); exit(1); }

    if((fd = open(argv[1], O_RDWR)) < 0) { perror("could not open file"); exit(1); }

    channel_number = atoi(argv[2]);

    ioctl( fd, IOCTL_COMMAND_ID, channel_number);
    if((msg_len = read(fd, buf, 128)) < 0) { perror("reading failed"); exit(1); }
    if(write(1, buf, msg_len) < 0) { perror("writing failed"); exit(1); }

    if(close(fd) < 0) { perror("error closinggg"); exit(1); }
    return 0;
}