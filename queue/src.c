//
// Created by mahmo on 11/2/2024.
//
#include "queue.h"
#include "stdio.h"
void creatqueue(queue *q){
    q->size=0;
    q->insert=-1;
    q->erase=0;
}
int size( queue *q){
    return q->size;
}
int isfull( queue *q){
    return (q->size==N-1? 1:0);
}
int isempty( queue *q){
    return (q->size==0 ? 1 : 0);
}
void push(queue *q,type item){
    if(q->size==N){
        printf("error queue already full >>>");
    }else{
        q->items[++q->insert%N]=item;
        q->size++;
    }
}
type pop(queue *q){
    if(q->size==0){
        printf("error queue already empty >>>");
    }else{
        q->erase++;
        q->size--;
    }
}
type top(queue *q){
    return q->items[q->erase];
}
void traverse(queue *q, void (*pf)(type e)) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < q->size; ++i) {
        int index = (q->erase + i) % N;
        pf(q->items[index]);
    }
}
