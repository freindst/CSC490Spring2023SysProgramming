#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    FILE *stream;

    stream = fopen("sample.txt", "r");

    int count = 0;
    int c;

    while((c = fgetc(stream))!=EOF){
        count++;
    }

    printf("fgetc(): sample.txt has %d chars.\n", count);
    fclose(stream);

    stream = fopen("sample.txt", "r");
    count = 0;
    const int unitSize = 100;
    char buf [unitSize];

    while((fgets(buf, unitSize, stream)) != NULL){
        count = count + strlen(buf);
    }

    printf("fgets(): sample.txt has %d chars.\n", count);
    fclose(stream);

    return 0;
}