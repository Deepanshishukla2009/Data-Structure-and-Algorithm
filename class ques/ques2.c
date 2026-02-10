#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

int main(){
    int n,i;
   struct node *head = NULL, *temp = NULL, *newnode = NULL;
    printf("enter value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode = (struct node*)malloc(sizeof(struct node));
 if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;   
            temp = newnode;
        } else {
            temp->next = newnode; 
            temp = newnode;
        }
    }

    printf("Linked list: ");
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while (temp != NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;

    }