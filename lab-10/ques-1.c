/*Adjacency matrix and adjacency list of a graph*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// ----------- Adjacency Matrix -----------
int matrix[MAX][MAX];
int vertices;

// ----------- Adjacency List -----------
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge to list
void addEdgeList(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Create Graph (both matrix & list)
void createGraph() {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize matrix and list
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);

        // Matrix
        matrix[src][dest] = 1;

        // List
        addEdgeList(src, dest);
    }
}

// Display Matrix
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Display List
void displayList() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        struct Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ----------- MAIN MENU -----------
int main() {
    int choice;

    while (1) {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Display Adjacency List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}