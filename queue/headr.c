//
// Created by mahmo on 11/2/2024.
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
void traverse(queue *q, void (*pf)(type e));
#endif //UNTITLED2_QUEUE_H
