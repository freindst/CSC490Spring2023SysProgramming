#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct myStack{
    char ** content;
    int size;
    int count;
} astack;

astack initiate(int s_size);

void push(astack *s, char * str);

char * pop(astack * s);

char * peek(astack * s);

void destroyStack(astack * s);

int main(){
    char * oldPath = "genesis.txt";
    char * newPath = "genesis_line_reversed.txt";

    FILE * inputStream, * outputStream;
    inputStream = fopen(oldPath, "r");
    outputStream = fopen(newPath, "w");

    //line count
    //method 1: read all into buffer, and search for '\n'
    //method 2: loop through fgets how many times it stops

    int charCount = 0;
    char c;

    while((c = fgetc(inputStream)) != EOF){
        if (c == '\n'){
            charCount++;
        }
    }
    fseek(inputStream, 0, SEEK_SET);

    struct myStack s;
    s = initiate(charCount);

    char * lineBuffer;
    lineBuffer = (char *)malloc(1000);
    char * temp;
    while((temp = fgets(lineBuffer, 1000, inputStream)) != NULL){
        push(&s, lineBuffer);
        printf("%d", s.count);
    }

    while(s.count > 0){
        lineBuffer = pop(&s);
        fputs(lineBuffer, outputStream);
    }
    
    fclose(inputStream);
    fclose(outputStream);

    free(lineBuffer);
    destroyStack(&s);

    return 0;
}

struct myStack initiate(int s_size){
    struct myStack s; 
    s.count = 0;
    s.size = s_size;
    s.content = malloc(sizeof(char *) * s_size);
    return s;
}

//stack can push
void push(astack *s, char * str){
    s->content[s->count] = (char*)malloc(1000);
    strcpy(s->content[s->count], str);
    s->count = s->count + 1;
}

//stack can pop
char * pop(astack *s){
    char * ret = s->content[s->count - 1];
    s->content[s->count - 1] = "";
    s->count = s->count - 1;
    return ret;
}

//stack can peak
char * peek(astack *s){
    char * ret = s->content[s->count - 1];
    return ret;
}

void destroyStack(astack *s){
    int i;
    for(i = 0; i < s->size; i++){
        char * member;
        member = s->content[i];
        free(member);
    }
    free(s->content);
}
