#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createlist(struct node *head, int val)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void findMiddle(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element = %d\n", slow->data);
}

int main()
{
    struct node *head = NULL;
    int n, i, element;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &element);
        head = createlist(head, element);
    }

    printf("Linked List:\n");
    display(head);

    findMiddle(head);

    return 0;
}
