#include "bst..h"
#include <stdio.h>
#include <stdlib.h>
void create(bst *t) {
    t->t = NULL;
    t->size = 0;
}
void insert(bst *t, type val) {
    node *pn = (node *)malloc(sizeof(node));
    if (!pn) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    pn->value = val;
    pn->left = NULL;
    pn->right = NULL;

    if (t->t == NULL) {
        t->t = pn;
    } else {
        node *cur = t->t, *prev = NULL;

        while (cur) {
            prev = cur;
            if (val > cur->value) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
  // cur null prev parent
        if (val > prev->value) {
            prev->right = pn;
        } else {
            prev->left = pn;
        }
    }
    t->size++;
    printf("Insertion of value %d is done.\n", val);
}
type findMin(node *root) {
    if (root == NULL) {
        printf("Error: Tree is empty!\n");
        exit(EXIT_FAILURE);
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->value;
}
void erase(bst *t, type val) {
    if (t->t == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    int found = 0;
    t->t = eraseNode(t->t, val, &found);
    if (found) {
        printf("Value %d deleted successfully.\n", val);
        t->size--;
    } else {
        printf("Value %d not found in the tree.\n", val);
    }
}
node* eraseNode(node *root, type val, int *found) {
if(root==NULL ){
    return root;
}
if(root->value >val){ // 5  >> 4
    root->left=eraseNode(root->left,val,found);
}else if(root->value<val){
    root->right= eraseNode(root->right,val,found);
}else{
    *found=1;
    if(root->right==NULL){
        node *temp=root->left; //null
        free(root);
        return temp;
    }else if(root->left==NULL){
        node *temp=root->right;
        free(root);
        return temp; // 16
    }
    int vl= findMin(&root->right);   // 8
    root->value=vl;
    eraseNode(&root->right,vl,found);
}
    return root;
}

int find(bst *t, type val) {
    node *cur = t->t;
    while (cur) {
        if (val == cur->value) {
            return 1;
        } else if (val < cur->value) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return 0;
}


int isfull(bst *t) {
    return 0;
}

int isempty(bst *t) {
    return t->t == NULL;
}

int size(bst *t) {
    return t->size;
}
int hh(node *root) {
    if (root == NULL) {
        return 0;
    }
    int l = hh(root->left);
    int r = hh(root->right);
    return (l > r ? l : r) + 1;
}

int height(bst *t) {
    if (t->t == NULL) {
        return 0;
    } else {
        return hh(t->t);
    }
}


