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

// Remove duplicates (sorted list)
struct node* removeDuplicates(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL && temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            struct node *dup = temp->next;
            temp->next = dup->next;
            free(dup);
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

// Traversal
void traverse(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n, i, element;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &element);
        head = insertAtEnd(head, element);
    }

    printf("Original List:\n");
    traverse(head);

    head = removeDuplicates(head);

    printf("After Removing Duplicates:\n");
    traverse(head);

    return 0;
}