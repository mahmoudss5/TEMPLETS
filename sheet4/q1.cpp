#include <stdio.h> 
#include "queue_linked_list.h" 
int main(void) { 
 queue  q; 
    creatqueue(&q); 
    int  choice; 
    while (choice != 4) { 
        printf("\nMenu:\n"); 
        printf("1. Add a New Process\n"); 
        printf("2. Serve a Process\n"); 
        printf("3. Number of Waiting Processes\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        if(choice==1){ 
            int x,y,z; 
            printf(" please enter the id and piort and burst 
time"); 
            scanf("%d %d %d",&x,&y,&z); 
            push(&q,x,y,z); 
        }if(choice==2){ 
            pop(&q); 
}if(choice==3){ 
printf("the waiting is : %d", size(&q)); 
} 
} 
return 0; 
} 
// 
// Created by mahmo on 2024-12-01. 
// 
#include <stdio.h> 
#include "queue_linked_list.h" 
#include "stdlib.h" 
void creatqueue(queue *q){ 
q->front=NULL; 
q->insert=NULL; 
q->size=0; 
} 
void push(queue *q, type idd, int pirt, int bursttime) { 
node *pn = (node*) malloc(sizeof(node)); 
pn->id = idd; 
pn->burst = bursttime; 
    pn->piort = pirt; 
    pn->next = NULL; 
 
    if (q->size == 0) { 
        q->front = pn; 
        q->insert = pn; 
    } else { 
        node *pt = q->front; 
        node *prev = NULL; 
 
        if (pn->piort < pt->piort) { 
            pn->next = q->front; 
            q->front = pn; 
        } else { 
            while (pt != NULL && pt->piort <= pn->piort) { 
                prev = pt; 
                pt = pt->next; 
            } 
 
            prev->next = pn; 
            pn->next = pt; 
 
            if (pt == NULL) { 
q->insert = pn; 
} 
} 
} 
q->size++; 
} 
void pop(queue *q) { 
if (q->size == 0) { 
printf("Queue is empty, we cannot pop\n"); 
return; 
} 
printf("Item served, ID is: %d\n", q->front->id); 
node *pt = q->front; 
q->front = q->front->next; 
if (q->front == NULL) { 
q->insert = NULL; 
}free(pt); 
q->size--; 
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
// 
// Created by mahmo on 2024-12-01. 
// 
#ifndef UNTITLED5_QUEUE_LINKED_LIST_H 
#define UNTITLED5_QUEUE_LINKED_LIST_H 
#define type int 
typedef struct queueNODE{ 
type burst; 
int piort; 
int id; 
struct queueNODE *next; 
}node; 
typedef  struct QUEUE{ 
node *insert; 
int size; 
node *front; 
}queue; 
void creatqueue(queue *s); 
void push(queue *s,type id, int piort,int bursttime); 
void pop(queue *s); 
int size(queue *s); 
int isempty(queue *s); 
int isfull(queue *s); 
#endif //UNTITLED5_QUEUE_LINKED_LIST_H
