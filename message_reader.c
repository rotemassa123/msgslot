#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>


int main(int argc, char *argv[]){
    int fd;
    char buf[128];
    if(argc != 3){ return -1; }

    fd = open(argv[1], O_RDWR);
    ioctl( fd, 7, 1);
    read(fd, buf, 128);//might need to change size of buffer 128
    //Print the message to standard output (using the write() system call)
    close(fd);
    return 0;
}