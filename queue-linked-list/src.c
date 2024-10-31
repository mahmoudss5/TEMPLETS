//
// Created by mahmo on 10/31/2024.
//
#include <stdio.h>
#include "queue.h"
#include "stdlib.h"

void creatqueue(queue *q){
    q->front=NULL;
    q->insert=NULL;
    q->size=0;
}
type push(queue *q,type elemnt){
    node *pn = (node*) malloc(sizeof(node));
    pn->info = elemnt;
    pn->next = NULL;
    if (q->size == 0) {
        q->front = pn;
        q->insert = pn;
    } else {
        q->insert->next = pn;
        q->insert = pn;
    }
    q->size++;
}
type pop(queue *q){
    if (q->size == 0) {
        printf("Queue is empty, we cannot pop\n");
        return 0;
    }
    type x = q->front->info;
    node *pt = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->insert = NULL;
    }
    free(pt);
    q->size--;
    return x;
}
int size(queue *s){
    return s->size;
}
int isempty(queue *s){
    return s->front==NULL;
}
int isfull(queue *s){
    return 0;
}
