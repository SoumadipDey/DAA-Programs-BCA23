#include <stdio.h>
#include <stdlib.h>

struct Node {
    char vertex;
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* tail;
};

void displayAdjList(struct List** adjList, int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %c: ", i + 'A'); // Use 'A' for char representation
        struct Node* curr = adjList[i]->head;
        while (curr) {
            printf("%c -> ", curr->vertex); // Print as char
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void createEdge(struct List** adjList, int src, int dst, int edgeType) {
    // Add edge from src to dst
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dst + 'A';
    newNode->next = NULL;
    if (adjList[src]->head == NULL) {
        adjList[src]->head = newNode;
    } else {
        adjList[src]->tail->next = newNode;
    }
    adjList[src]->tail = newNode;
    
    if (edgeType == 0) { // Create a bidirectional edge if edgeType is 0
        // Add edge from dst to src
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = src + 'A';  
        newNode->next = NULL;
        if (adjList[dst]->head == NULL) { // If the list is empty, initialize both head and tail
            adjList[dst]->head = newNode;
        } else {
            adjList[dst]->tail->next = newNode;
        }
        adjList[dst]->tail = newNode; 
    }
}

struct List** createGraph(int V, int E){
    char src, dst; 
    int graphtype;
    printf("Graph type: 0) Undirected 1) Directed\nChoice: ");
    scanf("%d", &graphtype);

    // Allocate memory for the adjacency list
    struct List** adjList = (struct List**)malloc(V * sizeof(struct List*));
    for (int i = 0; i < V; i++) {
        adjList[i] = (struct List*)malloc(sizeof(struct List));
        adjList[i]->head = NULL;
    }
    // Take input of Edges
    for (int i = 0; i < E; i++) {
        printf("\nEnter Src and Dst of Edge %d: ", i + 1);
        getchar();  // To consume newline character left by previous scanf
        scanf("%c %c", &src, &dst);
        createEdge(adjList, src - 'A', dst - 'A', graphtype);
    }
    return adjList;
}