/* Binary Tree using array*/

#include <stdio.h>

#define SIZE 10

int tree[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

void insert(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == -1) {
            tree[i] = value;
            return;
        }
    }
    printf("Tree is full\n");
}


void inorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}


void preorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}


void postorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}


void display() {
    printf("Binary Tree (Array form):\n");
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    init();

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    printf("Inorder: ");
    inorder(0);

    printf("\nPreorder: ");
    preorder(0);

    printf("\nPostorder: ");
    postorder(0);

    return 0;
}