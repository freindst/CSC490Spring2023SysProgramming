//create two file, sample_1.txt and sample_2.txt
//sample_1 contains first 1180/2 = 590bytes from sample.txt
//smaple_2 contains second 590 bytes from sample.txt

//the beginning spot of the buffer
//call write() twice, 
//first time write first 590bytes from buffer to sample_1.txt
//second time from second 590 bytes to the new sample_2.txt
//truncate can be used in making the first 590 bytes

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//make a copy of a file
int main(){
    //char * buf;
    char tempbuf [1000];

    char * originalPath = "sample.txt";

    int fd;
    fd = open(originalPath, O_RDONLY);

    //count the length
    int length = 0;
    int readRet;

    //tempbuf = malloc(10); //allocate memory space for buffer
    while ((readRet = read(fd, tempbuf, 1000)) > 0){
        length = length + readRet;
    }
    printf("There are %d bytes in sample.txt.", length);

    //free(tempbuf);

    //buf = (char *)malloc(length);
    int halfLength = length / 2;
    char buf1 [halfLength];
    char buf2 [length - halfLength];//3, 1 -> 2
    lseek(fd, 0, SEEK_SET);
    readRet = read(fd, buf1, halfLength);
    if (readRet <= 0){
        printf("Read Error");
    }
    readRet = read(fd, buf2, length - halfLength);
    readRet = close(fd);

    //write all bytes from buffer into new sample_copy.txt
    fd = creat("sample_1.txt", 0644);
    int writeRet;
    if ((writeRet = write(fd, buf1, halfLength)) < 0){
        printf("Write error.");
    }
    fd = creat("sample_2.txt", 0644);
    
    if ((writeRet = write(fd, buf2, length - halfLength)) < 0){
        printf("Write error.");
    }
    close(fd);

    //free(buf);

    return 0;
}
