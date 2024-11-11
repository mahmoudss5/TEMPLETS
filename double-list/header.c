//
// Created by mahmo on 2024-11-11.
//
#ifndef UNTITLED2_LIST_H
#define UNTITLED2_LIST_H
#define type int
typedef  struct Node{
    type info;
    struct Node *next;
    struct Node *prev;
}node;
typedef struct Head{
    int size;
    node *last;
    node *first;
}list;
void createlist(list *l);
void pushpack( list *l,type elemnt );
void pushfront( list *l,type elemnt );
type erasepack( list *l);
type erasefront( list *l);
int isempty(list *l);
int isfull(list *l);
int getsize(list *l);

#endif //UNTITLED2_LIST_H
