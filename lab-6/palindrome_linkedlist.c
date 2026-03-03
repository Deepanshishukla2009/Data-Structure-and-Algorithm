#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    struct node*p=head;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}
struct node *reverse(struct node *head)
{
    struct node *current=head;
    struct node *prev=NULL;
    struct node *p=NULL;
    while(current!=NULL)
    {
        p=current->next;
        current->next=prev;
        prev=current;
        current=p;
    }
    return prev;
}
int main()
{
    struct node *head=NULL;
    struct node *newnode=NULL;
    struct node *temp=NULL;
    int i,n;
    printf("Enter the number of nodes you want:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d:",i+1);
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
    }
   
    temp=reverse(head);
    if(head==temp)
    {
        printf("Palindrome list.\n");
    }
    else
    {
        printf("Not Palindrome list.\n");
    }
    return 0;
}