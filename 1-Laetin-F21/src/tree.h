#ifndef LAB5_TREE_H
#define LAB5_TREE_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node_t node_t;
struct node_t {
    int key;
    int numberOfNodes;
    node_t *left, *right;
    node_t *father;
};

int AddToTree(node_t **tree, node_t *father, int key);
node_t* FindKLowerTree(node_t *tree, int key, int k);
void ClearTree(node_t **tree);

#endif //LAB5_TREE_H