#include <stdio.h>
#include <stdbool.h>
#include "StackOfDoublesModule.h"


#define MAXVAL 100

static StackItem TheElements[MAXVAL];
static size_t sp;

StackItem Pop(void){
    return TheElements[--sp];
}

void Push(StackItem item){
    TheElements[sp++] = item;
}

bool IsEmpty(){
    return sp == 0;
}

bool IsFull(){
    return sp == MAXVAL;
}