//
// Created by mahmo on 2024-11-22.
//
#ifndef UNTITLED2_LIST_H
#define UNTITLED2_LIST_H
typedef int type;
typedef struct nodet {
    type info;
    struct nodet *next;
} node;

typedef struct hea {
    int size;
    node *head;
} list;
int isfull(list *l);
void creatlist(list *l);
void insert(list *l,type item,int pos);
type peak(list *l);
int count(list *l,type elemnt);
void joinlist(list *l1,list *l2);
type erase(list *l, int position);
#endif //UNTITLED2_LIST_H
