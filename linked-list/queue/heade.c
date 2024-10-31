//
// Created by mahmo on 10/29/2024.
//
#ifndef UNTITLED2_QUEUE_H
#define UNTITLED2_QUEUE_H
#define N 5
typedef int type;
typedef struct Queue {
   int size;
   int insert;
   int erase;
   type items[N];
}queue;
void creatqueue(queue *s);
int size( queue *s);
int isfull( queue *s);
int isempty( queue *s);
void push(queue *s,type item);
type pop(queue *s);
type top(queue *s);
/*void copy( stack *c,stack *s);
void traverse(stack *s,void(*pf)(type e));*/
#endif //UNTITLED2_QUEUE_H
