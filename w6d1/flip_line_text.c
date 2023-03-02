#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StringStack {
    char * * List;
    int Size;
    int Counter;
} Stack;

Stack Create(int s_size);

void Push(char * str, Stack *stack);

char * Pop(Stack *stack);

char * Peek(Stack *stack);

void DestroyStack(Stack *stack);

int main(){
    FILE * inputStream, * outputStream;
    inputStream = fopen("genesis.txt", "r");
    outputStream = fopen("genesis_line_reversed.txt", "w");

    int size = 0;
    int c;
    while((c = fgetc(inputStream)) != EOF){
        if ((char)c == '\n'){
            size = size + 1;
        }
    }

    struct StringStack stack;
    stack = Create(size);

    //move the file pointer to the beginning
    fseek(inputStream, 0, SEEK_SET);

    char * buf;
    buf = malloc(sizeof(char) * 1000);

    char * temp;

    while((temp = fgets(buf, 1000, inputStream)) != NULL){
        Push(buf, &stack);
    }

    while(stack.Counter > 0){
        temp = Pop(&stack);
        if (temp != NULL){
            fputs(temp, outputStream);
        }
        free(temp);
    }

    DestroyStack(&stack);
    fclose(inputStream);
    fclose(outputStream);


    return 0;
}

Stack Create(int s_size){
    Stack s;
    s.List = malloc(sizeof(char *) * s_size);
    s.Counter = 0;
    s.Size = s_size;
    return s;
}

void Push(char * str, Stack * stack){
    stack->List[stack->Counter] = malloc(1000);
    strcpy(stack->List[stack->Counter], str);
    stack->Counter = stack->Counter + 1;
}

char * Pop(Stack *stack){
    char * ret;
    ret = stack->List[stack->Counter - 1];
    stack->List[stack->Counter - 1] = "";
    stack->Counter = stack->Counter - 1;
    return ret;
}

char * Peek(Stack *stack){
    char * ret;
    strcpy(ret, stack->List[stack->Counter - 1]);
    return ret;
}

void DestroyStack(Stack *stack){
    int i;
    /*for (i = 0; i < stack->Size; i++){
        free(stack->List[i]);
    }*/
    free(stack->List);
}