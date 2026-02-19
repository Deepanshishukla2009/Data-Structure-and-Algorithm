#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void createList()
{
    int n, val, i;
    struct Node *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n == 0)
        return;

    for(i = 1; i <= n; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }
}
void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse()
{
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main()
{
    createList();

    printf("\nOriginal List:\n");
    display();

    reverse();

    printf("\nReversed List:\n");
    display();

    return 0;
}
