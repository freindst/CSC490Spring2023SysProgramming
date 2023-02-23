#include <stdio.h>
#include <stdlib.h>

//return the file size in bytes
int getFileSize(char * filePath);

//copy genesis.txt into genesis_copy.txt
void main(){
    //String path = "genesis.txt";
    char * path = "genesis.txt";
    char * newPath = "genesis_copy.txt";
    FILE * inputStream, * outputStream;
    inputStream = fopen(path, "r"); //r, w, r+, w+, a, a+
    outputStream = fopen(newPath, "w");

    int fileSize = getFileSize(path);

    printf("the input file size is %d bytes.", fileSize);

    char * buf;
    buf = malloc(fileSize);
    if (fread(buf, fileSize, 1, inputStream) > 0){
        fwrite(buf, fileSize, 1, outputStream);
    }
    
    fclose(inputStream);
    fclose(outputStream);
    free(buf);    
}

int getFileSize(char * filePath){
    FILE * stream;
    stream = fopen(filePath, "r");
    fseek(stream, 0, SEEK_END);
    int ret;
    ret = ftell(stream);
    fclose(stream);
    return ret;
}