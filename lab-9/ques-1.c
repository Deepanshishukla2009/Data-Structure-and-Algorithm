/* Binary Tree using array*/

#include <stdio.h>

#define SIZE 10

int tree[SIZE];

// Initialize
void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

// Insert (level order)
void insert(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == -1) {
            tree[i] = value;
            return;
        }
    }
    printf("Tree is full\n");
}

// 🔹 Inorder (Left Root Right)
void inorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

// 🔹 Preorder (Root Left Right)
void preorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

// 🔹 Postorder (Left Right Root)
void postorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

// Display (simple array)
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