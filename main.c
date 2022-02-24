//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int data;
    int key;
    struct node *next;
};

struct nodes * addNode (int newData, int newKey) {
    //create node
    struct nodes newNode = (struct nodes*)
    struct nodes newNode = {.data = newData, .key = newKey, .next = NULL};
    struct nodes* ptr = &newNode;
    return ptr;
};


int main() {
    struct nodes *root;
    root = (struct nodes *) malloc(sizeof(struct nodes));
    root = {.date = 0, .key = 0, .next = NULL};
    root->data = 13;
    root->key = 131;
    //*root = createNode(1, 1);

    printf("%d %d %p", root->data, root->key, &root);
    printf("\n%p", root);
    free(root);
    return 0;
}
