#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Scanner.h"
#define MAXOP 100 /* máx tamaño de operando u operador */

static bool estadoNumero(Token *t);
static bool estadoLexError(Token *t);
static bool estadoPunto(Token *t);
static bool estadoParteFracc(Token *t);
static bool estadoSuma(Token *t);
static bool estadoMenos(Token *t);
static bool estadoResta(Token *t);
static bool estadoMult(Token *t);
static bool estadoDiv(Token *t);
static bool estadoResultado(Token *t);
static bool nodigito(char c);


int i = 0;
char lexema[MAXOP];

bool GetNextToken(Token *t /*out*/){    
i = 0;
lexema[i] = getchar();
if(isdigit(lexema[i])){
  return estadoNumero(t);
}
else{
    switch (lexema[i])
    {
    case '+':
        return estadoSuma(t);
    case '-':
        return estadoMenos(t);
    case '*':
        return estadoMult(t);
    case '/':
        return estadoDiv(t);
    case '\n':
        return estadoResultado(t);
    case ' ':
        t->type = Space;
        return true;
     case EOF:
        return false;      
    default:
        return estadoLexError(t);
    }
}
}






bool nodigito(char c) {
    return (c != ' ' && c != '\t' && c != '*' && c != '+' && c != '-' && c != '/' && c != '\n' &&  c != EOF);
}

bool estadoNumero(Token *t){
   while (isdigit(lexema[++i] = getchar( ))){}
   if(lexema[i] == '.'){
        return estadoPunto(t);
   }
    else{
        if(nodigito(lexema[i])){
           printf("estado lex error %c",lexema[i]);
           return estadoLexError(t);
        }
        else
        {
            ungetc(lexema[i], stdin);
            t->type = Number;
            lexema[i] ='\0';
            t-> val=  atof(lexema);
            return true;
        }
    }
}


bool estadoPunto(Token *t){
    if(isdigit(lexema[++i] = getchar( ))){
        return estadoParteFracc(t);
    }
    else{
        return estadoLexError(t);
    }
}

bool estadoParteFracc(Token *t){
     while (isdigit(lexema[++i] = getchar( ))){}
     if(nodigito(lexema[i])){
        return estadoLexError(t);
      }
      else
        {
          ungetc(lexema[i], stdin);
          t->type = Number;
          lexema[i] ='\0';
          t-> val=  atof(lexema);
          return true;
        } 
}


bool estadoLexError(Token *t){
    t->type = LexError;
    t->lexeme = lexema[i];
    return false;
}

bool estadoSuma(Token *t){
    t->type = Addition;
    return true;
}

bool estadoResta(Token *t){
    t->type = Substraction;
    return true;
}

bool estadoMult(Token *t){
    t->type= Multiplication;
    return true;
}
bool estadoDiv(Token *t){
    t->type=Division;
    return true;
}
bool estadoResultado(Token *t){
    t->type = PopResult;
    return true;
}

bool estadoMenos(Token *t){
    char sgte = getchar( );
    if(sgte == ' '){
        ungetc(sgte, stdin);
        return estadoResta(t);
    }
    else if(isdigit(sgte)){
        ungetc(sgte, stdin);
        return estadoNumero(t);
    }
    else{
        return estadoLexError(t);
    }
}