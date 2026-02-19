// operation on linkedlist
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// -------- Create List --------
void createList()
{
    int n, val, i;
    struct Node *temp, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &val);

        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
             temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// -------- Display List --------
void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// -------- Insert at Beginning --------
void insertBeginning()
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;
}

// -------- Insert at End --------
void insertEnd()
{
    struct Node *newNode, *temp = head;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// -------- Insert at Position --------
void insertPosition()
{
    int pos, i;
    struct Node *newNode, *temp = head;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        insertBeginning();
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// -------- Delete First Node --------
void deleteFirst()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// -------- Delete Last Node --------
void deleteLast()
{
    struct Node *temp = head, *prev;

    if(head == NULL)
    {
        printf("List empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// -------- Delete Node by Value --------
void deleteValue()
{
    int val;
    struct Node *temp = head, *prev;

    printf("Enter value to delete: ");
    scanf("%d", &val);

    if(head == NULL)
        return;

    if(head->data == val)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// -------- Count Nodes --------
void countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", count);
}

// -------- Search Element --------
void search()
{
    int key, pos = 1;
    struct Node *temp = head;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found\n");
}

// -------- Main Function --------
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete First Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Delete Node by Value\n");
        printf("9. Count Nodes\n");
        printf("10. Search Element\n");
        printf("11. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createList(); break;
            case 2: display(); break;
            case 3: insertBeginning(); break;
            case 4: insertEnd(); break;
            case 5: insertPosition(); break;
            case 6: deleteFirst(); break;
            case 7: deleteLast(); break;
            case 8: deleteValue(); break;
            case 9: countNodes(); break;
            case 10: search(); break;
            case 11: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
