#ifndef ScannerIncluido
#define ScannerIncluido
#include <stdbool.h>
enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 Space = ' ',
 LexError
};
typedef enum TokenType TokenType;
typedef double TokenValue;
typedef struct{
 TokenType type;
 TokenValue val;
 char lexeme;
}Token;
bool GetNextToken(Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido.
#endif
