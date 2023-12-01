#ifndef StackIncluido
#define StackIncluido
#include <stdbool.h>
typedef double StackItem;

void Push(StackItem item);
StackItem Pop(void);
bool IsEmpty(void);
bool IsFull(void);
#endif