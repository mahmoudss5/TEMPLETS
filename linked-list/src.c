//
// Created by mahmo on 2024-11-22.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void creatlist(list *l){
    l->head=NULL;
    l->size=0;
}
int isfull(list *l){
    return 0;
}
void insert(list *l,type item,int pos){
    if(pos>l->size+1 || pos<1){
        printf("invalid posstion");
        return;
    }
    node *pn=(node*) malloc(sizeof(node));
    pn->info=item;
    if(l->size==0){
        l->head=pn;
        pn->next=l->head;
    }else{
        node *pt=l->head;
        for (int i = 0; i <pos-1 ; ++i) {
            pt=pt->next;
        }
        pn->next=pt->next;
        pt->next=pn;
    }
    l->size++;
}
type peak(list *l) {
    if (l->head == NULL) {
        printf("List is empty!\n");
        return 0;
    }
    node *pt = l->head;
    for (int i = 0; i <l->size-1 ; ++i) {
        pt=pt->next;
    }
    return pt->info;
}
int count(list *l,type elemnt){
    int cnt=0;
    node *pt=l->head;
    for (int i = 0; i <l->size ; ++i) {
        if(pt->info==elemnt) cnt++;
        pt=pt->next;
    }
    return cnt;
}
type erase(list *l, int position) {
    if (l->head == NULL) {
        printf("Error: List is empty.\n");
        return 0;
    }

    if (position < 0) {
        printf("Error: Invalid position.\n");
        return 0;
    }

    node *current = l->head;
    type elem;
    if (position == 0) {
        elem = current->info;
        l->head = current->next;
        free(current);
        return elem;
    }
    node *prev = NULL;
    for (int i = 0; i < position; i++) {
        if (current == NULL) {
            printf("Error: Position out of range.\n");
            return 0;
        }
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Position out of range.\n");
        return 0;
    }

    elem = current->info;
    prev->next = current->next;
    free(current);

    return elem;
}
void joinlist(list *l1,list *l2){
    if (l1->head == NULL) {
        l1->head = l2->head;
        return;
    }
    node *pt = l1->head;
    while (pt->next != NULL) {
        pt = pt->next;
    }
    pt->next = l2->head;
}
