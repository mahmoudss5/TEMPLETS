//
// Created by mahmoud on 10/31/2024.
//
#ifndef LINKED_STACK_STACK_LINKEDLIST_H
#define LINKED_STACK_STACK_LINKEDLIST_H
#define type int
typedef struct STACKNODE{
type info;
struct STACKNODE *next;
}node;

typedef  struct Stack{
    int size;
    node *top;
}stack;

void creatstack(stack *s);
type push(stack *s,type elemnt);
type pop(stack *s);
int size(stack *s);
int isempty(stack *s);
int isfull(stack *s);
#endif //LINKED_STACK_STACK_LINKEDLIST_H
