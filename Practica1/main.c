#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "evaluador.h"
#include "stack.h"
int add_concat(char a,char b){
    return (( isalpha(a) && isalpha(b) ) || 
            ( ( a=='*' || a=='+' ) && isalpha(b) ) || 
            ( a==')' && b=='(' ));
}
char *add_concat_str(char *er){
    int tam = strlen(er),i,j,k;
    if(tam == 1) return er;
    char *cadConcat = (char *)malloc(sizeof(char)*(2*tam-1)); *cadConcat = '\0';
    for (k = i = 0,j=1; i < tam; i++,j++)
    {
        cadConcat[k] = er[i];
        if( add_concat(er[i],er[j]) ){
            cadConcat[++k] = '.';
        }
        cadConcat[++k] = er[j];
    }
    return cadConcat;
}





int main(int argvc,char *argv[]){
    if(1){
        printf("si\n");
    }
    char *cad = add_concat_str(argv[1]);
    printf("%s",cad);
    char *post = conv_infix_sufix(argv[2]);
    printf("infix:\n%s\npost:\n%s\n",argv[2],post);
    double res = eval_sufix(post);
    printf("\nResult: %f",res);
    return 0;
}

