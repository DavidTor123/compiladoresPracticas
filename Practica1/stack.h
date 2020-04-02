#ifndef STACK_H
#define STACK_H
#include <stdint.h>
#include <stdio.h>
#include "tipodato.h"
typedef 
    struct s
    {
        Nodo *cima;
        int tamanio;
    }
Stack;

Stack * newStack();
int pushC(Stack *s,char car);
int push(Stack *s,Nodo *node);
Nodo *pop(Stack *s);
int empty(Stack *s);
Nodo *tope(Stack *s);

#endif