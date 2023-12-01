%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
void yyerror(char *);
%}
%option noyywrap
separador ([ \t])+
DIGITO [0-9]
%% 
"-"?{DIGITO}+("."{DIGITO}+)? { yylval.real=atof(yytext); return NUMBER;}
"+"                   {return ADDITION;}
"-"                   {return SUBTRACTION;}
"*"                   {return MULTIPLICATION;}
"/"                   {return DIVISION;}
{separador}           {;}
"\n"                  {return POP;}
<<EOF>> { exit(0); } 
.                     {yyerror(yytext);}
%%