//
// Created by Wilson Scott on 2022-02-23.
//
#include <stdio.h>
#include <stdlib.h>

struct nodes { //define struct for nodes
    int data;
    struct nodes *next;
};

struct nodes* replaceHead (struct nodes *head, int newData) //Add link to start of list
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

void addNode (struct nodes *head, int newData) //Add Node to end of list
{
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

void printLinks(struct nodes *head) //Print all items of list
{
    struct nodes *current = head;
    while (current->next) {
        printf("\ndata: %d", current->data);
        current = current->next;
    }
    printf("\ndata: %d", current->data);
    printf("\nend");
}

void clearList(struct nodes *link) //Clear list, free memory
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

int findLink(struct nodes *head, int data)
{
    struct nodes *current = head;
    int location = 0;
    while (current) {
        if (current->data == data) {
            return location;
        }
        ++location;
        current = current->next;
    }
    return location;
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

    //test new node creation
    addNode(head, 1);
    addNode(head, 2);
    printLinks(head);

    head = replaceHead(head, 4);
    printLinks(head);
    clearList(head);

    return 0;
}
