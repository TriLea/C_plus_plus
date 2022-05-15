/*
Code below originally from 
tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
"Linked List Program in C"
removed sort and reverse functions
changed tutorialspoint key to data used in search
for use at:

Bellevue College CS212 programming assignment
W.P. Iverson, instructor
April 2022
*/

/*
* Edited by: Tristan Lea
* Date: 5/12/22
*/

#include <stdio.h>
#include <stdlib.h>

// basic linked list data structure
struct node {
    int data;
    struct node* next;
};

void printFirst(struct node head)
{
    printf("First: %d", head.data);
}

//display the list
void printList(struct node* head) {
    struct node* ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL) {
        printf("(%d) ", ptr->data);
        ptr = ptr->next;
    }

    printf(" ]");
}


//insert link at the first location
void insertFirst(struct node** head, int data) {
    //create a link to memory allocation of node size
    struct node* link = (struct node*)malloc(sizeof(struct node));

    link->data = data;

    //point it to old first node
    link->next = (*head);

    //point first to new first node
    (*head) = link;
}

void addLast(struct node** head, int data)
{
    struct node* link = (struct node*)malloc(sizeof(struct node));

    if (link == NULL)
    {
        return;
    }
    
    link->data = data;
    link->next = NULL;

    while (*head != NULL) {
        
        head = &(*head)->next;
    }

    *head = link;
}

void deleteBack(struct node** head)
{
    struct node* parent = *head;
    struct node* ptr = *head;

    if ( ptr == NULL)
    {
        return;
    }

    while (ptr->next != NULL) {

        parent = ptr;
        ptr = ptr->next;
    }

    parent->next = NULL;  

    free(ptr);
}

void switchPairs(struct node** head)
{
    struct node* ptr = *head; 
    struct node* temp;

    while (*head != NULL)
    {
        ptr = *head;

        if (ptr->next == NULL)
        {
            return;
        }

        *head = ptr->next;
        temp = (*head)->next;
        (*head)->next = ptr;
        ptr->next = temp;

        head = &(ptr->next); // send the pointer forward to continue the sort loop
    }
}

void stutter(struct node** head)
{
    struct node* ptr = *head;

    while (ptr != NULL) {

        struct node* link = (struct node*)malloc(sizeof(struct node));
        link->next = NULL;

        link->data = ptr->data;

        link->next = ptr->next;

        ptr->next = link;

        ptr = link->next;
    }
}

void removeAll(struct node** head, int data)
{
    struct node* ptr = *head;

    while (*head != NULL) {

        ptr = *head;

        if (ptr->data == data)
        {
            *head = ptr->next;

            free(ptr);
        }
        else
        {
            head = &(*head)->next;
        }
    } 


    
}


int ProcessData(double num, int x = 2) {};

int ProcessData(double num, int x) {};