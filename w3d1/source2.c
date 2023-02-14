#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int fd;
    // in c, string is a char array ending with \n
    // read write execute 111 => 777
    // 6<=110, 4<=100, 4<=100: 644
    fd = open("text1.txt", O_CREAT);
    
    if (fd == -1){
        printf("%s", "open error");
    } else {
        printf("text.txt is open at fd = %d", fd);
    }

    if (close(fd) == -1){
        printf("%s", "close error");
    } else {
        printf("file descriptor has closed.");
    }
}