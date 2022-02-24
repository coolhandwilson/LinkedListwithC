//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int key;
    struct nodes *next;
};

struct nodes* replaceHead (struct nodes *root)
{

}

void addNode (struct nodes *root, int newKey) {
    //create new node
    struct nodes *newNode;
    newNode = (struct nodes*) malloc(sizeof(struct nodes));
    if (newNode == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    newNode->key = newKey;
    newNode->next = NULL;
    printf("\nTest");
    // add new node to linked list
    struct nodes *current = root;
    while (current->next) {
        printf("\n%d", current->key);
        current = current->next;
    }
    printf("\n%d", current->key);
    current->next = newNode;
    //return newNode; // Return is likely unnecessary - need to add loop to sift through links and add that way
};


int main() {
    struct nodes *root;
    root = (struct nodes *) malloc(sizeof(struct nodes));
    if (root == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    root->next = NULL;
    root->key = 0;

    printf("\n%d %p", root->key, &root);
    printf("\n%p", root);
    //test new node creation
    addNode(root, 1);
    addNode(root, 2);

//    printf("\n%d %d %p", root->next->data, root->next->key, &root->next);
//    printf("\n%p", root->next);
    free(root->next->next);
    free(root->next);
    free(root);
    return 0;
}
