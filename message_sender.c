#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[]){
    int fd;
    if(argc != 4){ return -1; }

    fd = open(argv[1], O_RDWR);
    ioctl( fd, 7, 1);
    write(fd, &argv[3], 128);//might need to change size of buffer 128
    close(fd);
    return 0;
}