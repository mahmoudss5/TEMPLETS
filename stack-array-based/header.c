//
// Created by mahmo on 10/29/2024.
//
#ifndef UNTITLED1_STACK_H
#define UNTITLED1_STACK_H
#include "stack.h"
#define maxn 10
typedef int type;
typedef struct st{
    int top;
    type items[maxn];
}stack;
void creatstack(stack *s);
int size( stack *s);
int isfull( stack *s);
int isempty( stack *s);
type push(stack *s,type item);
type pop(stack *s);
type top(stack *s);
void copy( stack *c,stack *s);
void traverse(stack *s,void(*pf)(type e));
#endif //UNTITLED1_STACK_H
