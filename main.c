//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int data;
    struct nodes *next;
};

struct nodes* replaceHead (struct nodes *root, int newData)
{
    struct nodes *newRoot;
    newRoot = (struct nodes*) malloc(sizeof(struct nodes));
    if (newRoot == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    newRoot->data = newData;
    newRoot->next = root; //point to former head of linked list
    return newRoot; //return replace root var
}

void addNode (struct nodes *root, int newData) {
    //create new node
    struct nodes *newNode;
    newNode = (struct nodes*) malloc(sizeof(struct nodes));
    if (newNode == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    newNode->data = newData;
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
}

void printLinks(struct nodes *rootLink)
{
    struct nodes *current = rootLink;
    while (current->next) {
        printf("\ndata: %d", current->data);
        current = current->next;
    }
    printf("\ndata: %d", current->data);
    printf("\nend");
}

void clearList(struct nodes *link) //
{
    struct nodes *current = link;
    struct nodes *prev;
    while (current->next) {
        prev = current;
        current = current->next;
        free(prev);
        printf("\ncleared");
    }
}

int main() {
    struct nodes *root;
    root = (struct nodes *) malloc(sizeof(struct nodes));
    if (root == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    root->next = NULL;
    root->data = 0;

    printf("\n%d %p", root->data, &root);
    printf("\n%p", root);
    //test new node creation
    addNode(root, 1);
    addNode(root, 2);
    printLinks(root);

    root = replaceHead(root, 4);
    printLinks(root);
    clearList(root)



//    printf("\n%d %d %p", root->next->data, root->next->data, &root->next);
//    printf("\n%p", root->next);
    free(root->next->next->next);
    free(root->next->next);
    free(root->next);
    free(root);
    return 0;
}
