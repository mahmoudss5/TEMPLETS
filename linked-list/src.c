//
// Created by mahmo on 10/31/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"
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

