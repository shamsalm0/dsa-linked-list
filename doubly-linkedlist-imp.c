#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode;

void create() {
    bool flag = true;
    while (flag)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL) {
            head = newnode;
        } else {
            struct node *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;

      
            
        }
        char choice;
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to consume any leftover newline
        if (choice != 'y' && choice != 'Y') {
            flag = false;
        }
    }
    
}

void display() {
    struct node *temp = head;
    printf("Linked list data: ");
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print the data of the current node
        temp = temp->next;           // Move to the next node
    }
    printf("\n");
}
int main() {
  

   create();
   create();
   create();
   display();

   free(head);

    // printf("%d", sizeof(struct node));
    
    return 0;
}
