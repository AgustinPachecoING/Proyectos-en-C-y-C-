#include <stdio.h>
#include <stdlib.h>
#include "StackOfDoublesModule.h"
#include "Scanner.h"

static void push(StackItem item);
static StackItem pop();

int main(void){
    Token *token = (Token *)malloc(sizeof(Token));
    TokenValue op2;
    while (GetNextToken(token)) {
        switch (token->type) {
        case Number:
            push(token->val);
            break;
        case Addition:
            push(pop() + pop());
            break;
        case Multiplication:
            push(pop() * pop());
            break;
        case Substraction:
            op2 = pop();
            push(pop() - op2);
            break;
        case Division:
            op2 = pop( );
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf ("error: divisor cero\n");
            break;
        case PopResult:
            printf(" El resultado es \t%.8g\n", pop());
            break;
        case Space:
            continue;
        default:
            printf("error: comando desconocido");
            break;
        }
    }
    if(token->type== LexError){
        printf("Error Lexico encontrado: %c", token->lexeme);
    }
    free(token);
    return 0;
}

void push(StackItem item){
    if (!IsFull())
        Push(item);
    else
        printf("Error en la sintaxis, Verifique datos ingresados\n");
}
StackItem pop(){
    if (!IsEmpty())
        return Pop();
    else{
        printf("Error en la sintaxis, Verifique datos ingresados\n");
        return 0.0;
    }
}