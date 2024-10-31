//
// Created by mahmo on 10/31/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"
void creatstack(stack *s){
 s->top=NULL;
 s->size=0;
}
type push(stack *s,type elemnt){
    node *pn=(node*)malloc(sizeof (node));
    pn->info=elemnt;
    pn->next=s->top;
    s->top=pn;
    s->size++;
}
type pop(stack *s){
   node *pn=s->top;
   s->top=pn->next;
   type x=pn->info;
    free(pn);
    s->size--;
    return x;
}
int size(stack *s){
    return s->size;
}
int isempty(stack *s){
    return s->size==0;
}
int isfull(stack *s){
    return 0;
}


