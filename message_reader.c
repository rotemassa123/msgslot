#include <sys/fcntl.h>
#include <sys/unistd.h>

int main(int argc, char *argv[]){
    int fd;
    char buf[128];
    if(argc != 3){ return -1; }

    fd = open(argv[1], O_RDWR);
    //missing command: Set the channel id to the id specified on the command line
    read(fd, buf, 128);//might need to change size of buffer 128
    //Print the message to standard output (using the write() system call)
    close(fd);
    return 0;
}