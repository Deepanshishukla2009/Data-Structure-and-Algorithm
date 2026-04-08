#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverse(struct node *head) {
    struct node *p = head;
    while(p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct node* reverse(struct node *head) {
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int isPalindrome(struct node *head) {
    if(head == NULL || head->next == NULL) return 1;

    struct node *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    struct node *secondHalf = reverse(slow->next);

   
    struct node *p1 = head;
    struct node *p2 = secondHalf;
    while(p2 != NULL) {
        if(p1->data != p2->data) return 0;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 1;
}

int main() {
    struct node *head = NULL, *newnode = NULL;
    int i, n;
    printf("Enter the number of nodes you want:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
    }

    traverse(head);

    if(isPalindrome(head))
        printf("Palindrome list.\n");
    else
        printf("Not Palindrome list.\n");

    return 0;
}
