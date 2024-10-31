//
// Created by mahmo on 10/31/2024.
//

#ifndef LINKED__LIST_LINKED_LIST_H
#define LINKED__LIST_LINKED_LIST_H
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
#endif //LINKED__LIST_LINKED_LIST_H
