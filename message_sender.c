#include <sys/fcntl.h>
#include <sys/unistd.h>

int main(int argc, char *argv[]){
    int fd;
    if(argc != 4){ return -1; }

    fd = open(argv[1], O_RDWR);
    //missing command: Set the channel id to the id specified on the command line.
    write(fd, &argv[3], 128);//might need to change size of buffer 128
    close(fd);
    return 0;
}