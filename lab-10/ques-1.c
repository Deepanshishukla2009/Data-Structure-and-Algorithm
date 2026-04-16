/*BST using array*/

#include <stdio.h>
#define SIZE 100

int tree[SIZE];  

void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}

void insert(int value, int index) {
    if (index >= SIZE) {
        printf("Tree is full\n");
        return;
    }

    if (tree[index] == -1) {
        tree[index] = value;
        return;
    }

    if (value < tree[index]) {
        insert(value, 2 * index + 1);   // Left
    } else {
        insert(value, 2 * index + 2);   // Right
    }
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

void display() {
    printf("\nArray Representation:\n");
    for (int i = 0; i < 15; i++) {
        if (tree[i] == -1)
            printf("NULL ");
        else
            printf("%d ", tree[i]);
    }
    printf("\n");
}

int main() {
    init();

    insert(50, 0);
    insert(30, 0);
    insert(70, 0);
    insert(20, 0);
    insert(40, 0);
    insert(60, 0);
    insert(80, 0);

    printf("Inorder: ");
    inorder(0);

    printf("\nPreorder: ");
    preorder(0);

    printf("\nPostorder: ");
    postorder(0);

    display();

    return 0;
}