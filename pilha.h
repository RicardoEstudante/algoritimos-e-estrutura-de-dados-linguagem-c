// pilha.h - implementação dinamica sequencial de pilha

#include <stdlib.h>

typedef int ItemS;

typedef struct stack {
    int    max;
    int    top;
    ItemS *item;
} *Stack;

Stack stack(int m) {
    Stack P = malloc(sizeof(struct stack));
    P->max  = m;
    P->top = -1;
    P->item = malloc(m*sizeof(ItemS));
    return P;
}

int isEmpty(Stack P) {
    if( P->top == -1 ) return 1;
    else return 0;
}

int isFull(Stack P) {
    if( P->top == P->max-1 ) return 1;
    else return 0;
}

void push(ItemS x, Stack P) {
    if( isFull(P) ) { puts("stack is full!"); abort(); }
    P->top++;
    P->item[P->top] = x;
}

ItemS pop(Stack P) {
    if( isEmpty(P) ) { puts("stack is empty!"); abort(); }
    ItemS x = P->item[P->top];
    P->top--;
    return x;
}

ItemS top(Stack P) {
    if( isEmpty(P) ) { puts("stack is empty!"); abort(); }
    return P->item[P->top];
}

void destroy(Stack *Q) {
    free((*Q)->item);
    free(*Q);
    *Q = NULL;
}