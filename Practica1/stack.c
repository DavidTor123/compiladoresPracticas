#include "stack.h"
#include <stdlib.h>


Stack * newStack(){
    Stack *pila = (Stack *)malloc(sizeof(Stack));
    if (pila == NULL)
    {
        perror("Error creando la nueva pila\n");
        exit(0);
    }
    pila->tamanio = 0;
    return pila;
}
int pushC(Stack *s,char car){
    if (s == NULL)
    {
        printf("La pila es NULL");
        return -1;
    }
    Nodo *node = (Nodo *)malloc(sizeof(Nodo));
    if (node == NULL)
    {
        perror("Error creando el nuevo node\n");
        exit(0);
    }
    node->car = car;
    return push(s,node);
}
int push(Stack *s,Nodo *node){
    if (s == NULL)
    {
        printf("La pila es NULL");
        return -1;
    }
    node->sig = s->cima;
    s->cima = node;
    s->tamanio++;
    return 1;
}
Nodo *pop(Stack *s){
    if(s == NULL){
        perror("Pila no inicializada");
        exit(0);
    }else if( empty(s) )
    {
        perror("Pila esta vacia");
        return NULL;
    }
    Nodo *node = s->cima;
    s->cima = s->cima->sig;
    return node;
}
int empty(Stack *s){
    return (s == NULL || s->cima == NULL || s->tamanio == 0);
}
Nodo *tope(Stack *s){
    return (empty(s))?NULL:s->cima;
}
