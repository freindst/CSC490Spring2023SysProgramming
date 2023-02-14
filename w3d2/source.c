#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
    int fd;

    fd = open("test.txt", O_APPEND | O_RDWR);

    //write(fd, "Good morning!", 14);

    if (fd == -1){
        printf("%s", "opening error!");
    }
/*
    char buffer [10];
    //char * buffer;

    //buffer = malloc(buffer, 2);

    int ss;
    int length = 0;

    while((ss = read(fd, buffer, 10)) > 0){
        length += ss;
    }
    

    // buffer[1] = '\n';

    if (ss == -1){
        printf("%s", "reading errror!");
    } else {
        //printf("The first char in the file is %s", buffer);
    }

    //printf("There are %d characters in the test.txt", length);
    */
    int sss;

    sss = write(fd, "Good morning!", 13);
    if (sss == -1){
        perror("write error");
    }

    return 0;
}