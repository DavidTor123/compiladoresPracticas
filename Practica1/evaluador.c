
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int get_priority_in_stack(char op){
    int x; switch (op)
    {
    case '^':
        x = 3;
        break;
    case '*':
        x = 2;
        break;
    case '/':
        x = 2;
        break;
    case '+':
        x = 1;
        break;
    case '-':
        x = 1;
        break;
    case '(':
        x = 0;
        break;
    default:
        x = -1;
        break;
    }
    return x;
}
int get_priority_out_stack(char op){
    int x; switch (op)
    {
    case '^':
        x = 4;
        break;
    case '*':
        x = 2;
        break;
    case '/':
        x = 2;
        break;
    case '+':
        x = 1;
        break;
    case '-':
        x = 1;
        break;
    case '(':
        x = 5;
        break;
    default:
        x = -1;
        break;
    }
    return x;
}

char *conv_infix_sufix(char *cad){
    int tam = strlen(cad),i,j;
    char *post = (char *)malloc(sizeof(char)*tam); *post = '\0';
    Stack *pilaOperadores = newStack();
    char car,topePil;
    for (j = i = 0; i < tam; i++)
    {
        car = cad[i];
        if( isalnum(car) ){ // operando 
            post[j++] = (char)car;
        }else if( car == ')' ){ // ) 
            topePil = pop(pilaOperadores)->car;
            do{
                post[j++] = topePil;
                topePil = pop(pilaOperadores)->car;
            }while( topePil != '(' );
        }else { // operador

        printf("%c\n",car);
            short terminar = 0;
            while(terminar != 1){
                if(empty(pilaOperadores)){
                    pushC(pilaOperadores,car);
                    terminar = 1;
                }
                else{
                    if(get_priority_out_stack(car) <= 
                        get_priority_in_stack(tope(pilaOperadores)->car))
                    {
                        post[j++] = pop(pilaOperadores)->car;
                        pushC(pilaOperadores,car);
                        terminar = 1;
                    }else{
                        pushC(pilaOperadores,car);
                        terminar = 1;
                    }
                }
            }


        }
    }
    while ( !empty(pilaOperadores) )
    {
        post[j++] = pop(pilaOperadores)->car;
    }
    


    return post;
}