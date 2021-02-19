#include <stdio.h>
#include "pilha.h"

int main() {

    Stack P = stack(8*sizeof (char));

    int n , base, restDiv, aux;

    puts("Number");
    scanf("%i", &n );

    do {
        puts("One base between 2 and 36");
        scanf("%i", &base);
    } while(base < 2 || base > 36);


    do {
        restDiv = n % base;

        if (restDiv >= 10) {
            push(restDiv+55, P);
        }

        push(restDiv, P);
        n  = n  / base;

    } while(n  > 0);

    while( !isEmpty(P) ) {
        aux = pop(P);
        aux > 9 ? printf("%c", (char)aux) : printf("%d", aux);
    }

    destroy(&P);

    return 0;
}