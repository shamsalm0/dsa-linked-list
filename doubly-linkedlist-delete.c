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
struct node *head = NULL, *tail = NULL;
void create()
{
    bool flag = true;
    while (flag)
    {
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter a value: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        char ch;
        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch); // Notice the space before %c to consume any leftover newline
        if (ch != 'y' && ch != 'Y')
        {
            flag = false;
        }
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteAtEnd()
{
    struct node *temp = tail;
    temp->prev->next = NULL;
    tail = tail->prev;
    free(temp);
}

deleteAtPosition(pos)
{
    if(!head){
        printf("List is empty");
        return;
    }
    if (pos == 1)
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
            tail = NULL;
            return;
        }
        else
        {
            struct node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp); // <-- free the old head
            return;
        }
    }
    struct node *temp = head;
    int i = 0;
    while (i < pos - 1)
    {
        /* code */
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main()
{
    create();
    display();
    deleteAtEnd();
    display();
    deleteAtPosition(1);
    display();
    return 0;
}