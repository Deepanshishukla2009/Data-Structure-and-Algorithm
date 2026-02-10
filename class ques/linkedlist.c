#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node* next;
 };
 void traverse(struct node *head)
 {
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
 int main()
 {
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));

    head->data=100;
    head->next=second;
    second->data=200;
    second->next=third;
    third->data=300;
    third->next=NULL;
 
     printf("Linked list: ");
    traverse(head);

    
    free(head);
    free(second);
    free(third);

    return 0;
}