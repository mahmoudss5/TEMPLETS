//
// Created by mahmo on 10/29/2024.
//
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
void creatstack(stack *s){
    s->top=-1;
}
int size( stack *s){
    return s->top+1;//
}
int isfull( stack *s){
    return (s->top==maxn-1 ? 1 :0);
}
int isempty( stack *s){
    return (s->top==-1 ? 1 :0);
}
type push(stack *s,type item){
    s->items[++s->top]=item;
}
type pop(stack *s){
    return s->items[s->top--];
}
void copy( stack *c,stack *s){
    for (int i = 0; i <= s->top ; ++i) {
        c->items[i]=s->items[i]; // 1 2 3 4 5 6 7 8 9
    }
}
void traverse(stack *s,void(*pf)(type e)){ //
    for (int i = s->top; i >=0 ; i--) {
        (*pf)(s->items[i]); //5
    }
}


