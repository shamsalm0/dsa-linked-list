#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    /* data */
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL, *tail=NULL;
void create(){
    bool choice = true;
    while (choice)
    {
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head==NULL){
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    char ch;
    printf("Do you want to add another node? (y/n): ");
    scanf(" %c", &ch);  // Notice the space before %c to consume any leftover newline
    if (ch != 'y' && ch != 'Y') {
        choice = false;
    }
}
    
}

void insertAtBeginning(int data){
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void insertAtEnd(int data){
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    newnode->next = NULL;
}
void display() {
    struct node *temp = head; // Start from the head of the list
    printf("Linked list data: ");
    while (temp != NULL) { // Traverse until the end of the list
        printf("%d ", temp->data); // Print the data of the current node

        temp = temp->next; // Move to the next node
    }
    printf("\n"); // Print a newline character after all nodes are displayed
}

int main() {
    create();
    insertAtEnd(97);
    insertAtBeginning(47);
    display();
    return 0;
}