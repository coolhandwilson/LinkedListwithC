//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int data;
    struct nodes *next;
};

struct nodes* replaceHead (struct nodes *head, int newData)
{
    struct nodes *newRoot;
    newRoot = (struct nodes*) malloc(sizeof(struct nodes));
    if (newRoot == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    newRoot->data = newData;
    newRoot->next = head; //point to former head of linked list
    return newRoot; //return replace head var
}

void addNode (struct nodes *head, int newData) {
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
    struct nodes *current = head;
    while (current->next) {
        printf("\n%d", current->data);
        current = current->next;
    }
    printf("\n%d", current->data);
    current->next = newNode;
}

void printLinks(struct nodes *head)
{
    struct nodes *current = head;
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
    free(current);
    printf("\ncleared");
}

int main() {
    //Create head of list
    struct nodes *head;
    head = (struct nodes *) malloc(sizeof(struct nodes));
    if (head == NULL) {
        printf("\nMemory Allocation Error.");
        exit(1);
    }
    head->next = NULL;
    head->data = 0;

    printf("\n%d %p", head->data, &head);
    printf("\n%p", head);
    //test new node creation
    addNode(head, 1);
    addNode(head, 2);
    printLinks(head);

    head = replaceHead(head, 4);
    printLinks(head);
    clearList(head);

    return 0;
}
