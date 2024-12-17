#ifndef UNTITLED6_BST_H
#define UNTITLED6_BST_H

#define type int

typedef struct Node {
    type value;
    struct Node *left;
    struct Node *right;
} node;

typedef struct BST {
    node *t;
    int size;
} bst;


void create(bst *t);
void insert(bst *t, type val);
void erase(bst *t, type val);
int find(bst *t, type val);
int isfull(bst *t);
int isempty(bst *t);
node* eraseNode(node *root, type val, int *found);
type findMin(node *root);
int size(bst *t);
int height(bst *t);
int hh(node *);
#endif // UNTITLED6_BST_H
