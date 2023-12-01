%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *s);
extern char * yytext;
%}
%union
{
    float real;
    char lex;
}
%token <real> NUMBER 
%token ADDITION 
%token SUBTRACTION 
%token MULTIPLICATION 
%token DIVISION
%token POP
%type <real> expr
%start Inicio
%% 

Inicio: expr

expr: NUMBER { $$ = $1; }
    | expr expr ADDITION { $$ = $1 + $2; }
    | expr expr SUBTRACTION { $$ = $1 - $2; }
    | expr expr MULTIPLICATION { $$ = $1 * $2; }
    | expr expr DIVISION { if ($2 != 0) $$ = $1 / $2; else { printf("Error: División por cero.\n"); exit(1); } }
    | expr POP {printf("Resultado: %.2f \n", $1);}
%% 
int main (void)
{
    yyparse();
    return 0;
}
void yyerror(char *s) { 
   printf("\nLEX ERROR: %s", s);
   exit(1);
}
int yywrap() {
    return 1;
}
