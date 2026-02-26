#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Insert at end
struct node* insertAtEnd(struct node *head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find nth node from end
void findNthFromEnd(struct node *head, int n)
{
    struct node *first = head;
    struct node *second = head;

    for(int i = 0; i < n; i++)
    {
        if(first == NULL)
        {
            printf("n is greater than number of nodes\n");
            return;
        }
        first = first->next;
    }

    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    printf("Nth node from end = %d\n", second->data);
}

int main()
{
    struct node *head = NULL;
    int n, i, element, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &element);
        head = insertAtEnd(head, element);
    }

    printf("Enter n (nth node from end): ");
    scanf("%d", &pos);

    findNthFromEnd(head, pos);

    return 0;
}