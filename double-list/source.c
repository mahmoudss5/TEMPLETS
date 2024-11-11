    //
    // Created by mahmo on 2024-11-11.
    //
    #include "list.h"
    #include <stdlib.h>
    #include <stdio.h>
    void createlist(list *l){
        l->size=0;
        l->last=NULL;
        l->first=NULL;
    } // node *pn=(node*) malloc(sizeof(node));
    void  pushpack( list *l,type elemnt ){
        node *pn=(node*) malloc(sizeof(node));
        pn->info = elemnt;
        pn->next = NULL;
        if (l->size == 0){
            pn->prev = NULL;
            l->first = pn;
            l->last = pn;
        } else {
            pn->prev = l->last;
            l->last->next = pn;
            l->last = pn;
        }
        l->size++;
    }
    void pushfront( list *l,type elemnt ){
        node *pn=(node*) malloc(sizeof(node));
        pn->info=elemnt;
        pn->prev=NULL;
        if(l->size==0){
         l->last=pn;
         l->first=pn;
         pn->next=NULL;
        }else{
            pn->next=l->first;
            l->first->prev=pn;
            l->first=pn;
        }
        l->size++;
    }
    type erasepack( list *l){
        if (l->size == 0) {
            printf("The list is empty, we cannot delete.\n");
            return (type)-1;
        }
        node *pt = l->last;
        type element = pt->info;

        if (l->size == 1) {
            l->first = NULL;
            l->last = NULL;
        } else {
            l->last = pt->prev;
            l->last->next = NULL;
        }

        free(pt);
        l->size--;
        return element;
    }
    type erasefront( list *l ){
        if (l->size == 0) {
            printf("The list is empty, we cannot delete.\n");
            return (type)-1;
        }
        node *pt = l->first;
        type element = pt->info;
        if(l->size==1){
            l->first=NULL;
            l->last=NULL;
        }else{
            l->first=pt->next;
            pt->next->prev=NULL;
        }
        free(pt);
        l->size--;
        return element;
    }
    int isempty(list *l){
        return l->size==0;
    }
    int isfull(list *l){
        return 0;
    }
    int getsize(list *l){
        return l->size;
    }
