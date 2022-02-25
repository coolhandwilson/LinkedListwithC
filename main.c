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
    return -1;
}

void deleteLink(struct nodes *head, int data) //Deletes the first node found with the target data, if any
{
    int index = -1;
    int counter = 0;
    struct nodes *prev, *current, *temp;
    current = head;

    while (current && index == -1) {
        if (current->data == data) {
            index = counter;
        }
        ++counter;
        prev = current;
        current = current->next;
    }

    if (index == -1) { //target data not found in linked list
        printf("\nNode not found.");
        return;
    }

    if (prev == NULL) { //prev is null if target data is in head node
        printf("\nRemove, replace head of list");
        temp = head;
        head = head->next;
        free(temp);
    } else if (current->next) { //if target data is in middle of list
        printf("\nRemoved node from middle section");
        prev->next = current->next;
        free(current);
    } else if (current->next == NULL) { // if target is tail of list
        printf("\nRemoved tail from list");
        prev->next = NULL;
        free(current);
    }
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
    int search1, search2;
    search1 = findLink(head, 4);
    printf("\nThe node is in position %d\n", search1);
    search2 = findLink(head, 100);
    printf("This should output negative 1 because the data doesn't exist: %d\n", search2);
    clearList(head);

    return 0;
}
