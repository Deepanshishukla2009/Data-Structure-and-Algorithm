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


struct node* mergeLists(struct node *l1, struct node *l2)
{
    struct node *head = NULL;
    struct node *current;

  
    if(l1->data <= l2->data)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    current = head;

   
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data <= l2->data)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

  
    if(l1 != NULL)
        current->next = l1;
    else
        current->next = l2;

    return head;
}

void traverse(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *list1 = NULL, *list2 = NULL, *merged;
    int n1, n2, i, x;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted elements:\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        list1 = insertAtEnd(list1, x);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted elements:\n");
    for(i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        list2 = insertAtEnd(list2, x);
    }

    merged = mergeLists(list1, list2);

    printf("Merged List:\n");
    traverse(merged);

    return 0;
}