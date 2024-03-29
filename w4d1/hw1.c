#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


//1. we open a file on hard drive
//fd = open("genesis.txt", READ);
//2. we copy all the characters from the file to an array on memory
//2.1 have a new array as the placeholder for the file characters
//char temp[2000]
//2.2 read all the characters from fd into temp
//ss = read(fd, temp, 2000);
//close(fd);
//3. we open a new file on hard drive
//fd1 = open("genesis_copy.txt", READ_WRITE, 0644);
//4. we copy the array of characters from the memory to the new file on hard drive.
//ss = write(fd1, temp, 2000)
//close(fd1);

//make a copy of a file
int main(){
    //char * buf;
    char tempbuf [1000];

    char * originalPath = "sample.txt";
    char * newFilePath = "sample_copy.txt";

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
    char buf [length];
    lseek(fd, 0, SEEK_SET);
    readRet = read(fd, buf, length);
    if (readRet <= 0){
        printf("Read Error");
    }
    readRet = close(fd);

    //write all bytes from buffer into new sample_copy.txt
    fd = creat(newFilePath, 0644);
    int writeRet;
    if ((writeRet = write(fd, buf, length)) < 0){
        printf("Write error.");
    }
    close(fd);

    //free(buf);

    return 0;
}

//(read)->data will be in the buffer
//open() sample.txt
//read()
//char [] as buffer
//length of the the buffer
//count until read return 0
//close() sample.txt

//create a new file
//open mode set to create, previllege to 0644

//write to the new file
//write buffer into the new file
//close()


