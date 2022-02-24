//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int data;
    int key;
    struct nodes *next;
};

void addNode (struct nodes *root, int newData, int newKey) {
    //create new node
    struct nodes *newNode;
    newNode = (struct nodes*) malloc(sizeof(struct nodes));
    newNode->data = newData;
    newNode->key = newKey;
    newNode->next = NULL;
    printf("\nTest");
    // add new node to linked list
    struct nodes *current = root;
    while (current->next) {
        printf("\n%d", current->data);
        current = current->next;
    }
    printf("\n%d", current->data);
    current->next = newNode;
    //return newNode; // Return is likely unnecessary - need to add loop to sift through links and add that way
};


int main() {
    struct nodes *root;
    root = (struct nodes *) malloc(sizeof(struct nodes));
    root->next = NULL;
    root->data = 13;
    root->key = 131;

    printf("%d %d %p", root->data, root->key, &root);
    printf("\n%p", root);
    //test new node creation
    addNode(root, 10, 14);
    addNode(root, 20, 14);

//    printf("\n%d %d %p", root->next->data, root->next->key, &root->next);
//    printf("\n%p", root->next);
    free(root->next->next);
    free(root->next);
    free(root);
    return 0;
}
