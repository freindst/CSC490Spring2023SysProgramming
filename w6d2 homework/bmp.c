#include <stdlib.h>
#include <stdio.h>

unsigned int bitsToInt(char * bits);

int main(){
    FILE * inputStream, * outputStream;
    inputStream = fopen("darthvador.bmp", "rb");
    //outputStream = fopen("mirrored.bmp", "wb");

    char intBuf[4];

    //read the width, height and size from header;
    int sizePos, heightPos, widthPos;
    sizePos = 2;
    heightPos = 22;
    widthPos = 18;
    unsigned int size, height, width;

    //move the file pointer to the pos
    fseek(inputStream, sizePos, SEEK_SET);
    //read 4 bytes out into buf;
    fread(intBuf, 4, 1, inputStream);
    size = bitsToInt(intBuf);

    fseek(inputStream, heightPos, SEEK_SET);
    fread(intBuf, 4, 1, inputStream);
    height = bitsToInt(intBuf);

    fseek(inputStream, widthPos, SEEK_SET);
    fread(intBuf, 4, 1, inputStream);
    width = bitsToInt(intBuf);

    printf("File size is %d bits\n", size);
    printf("File width is %d bits\n", width);
    printf("File height is %d bits\n", height);

    fclose(inputStream);

    return 0;
}


unsigned int bitsToInt(char * bits){ //argument is 8 bit * 4 array
    //bits = char[4]{'A', 'B', 'C', 'D'};
    return (unsigned char)bits[0] | ((unsigned char)bits[1] << 8) | ((unsigned char)bits[2] << 16) | ((unsigned char)bits[3] << 24);
}