//
// Created by mahmooud on 10/31/2024.
//
#ifndef QUEUE_LINKED_LIST_QUEUE_H
#define QUEUE_LINKED_LIST_QUEUE_H
#define type int
typedef struct queueNODE{
    type info;
    struct queueNODE *next;
}node;

typedef  struct QUEUE{
 node *insert;
    int size;
    node *front;
}queue;

void creatqueue(queue *s);
type push(queue *s,type elemnt);
type pop(queue *s);
int size(queue *s);
int isempty(queue *s);
int isfull(queue *s);
#endif //QUEUE_LINKED_LIST_QUEUE_H
