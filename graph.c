#include <stdio.h>
#include <stdlib.h>
struct Node {
    char vertex;
    int weight;
    struct Node* next;
};
struct List {
    struct Node* head;
    struct Node* tail;
};
void displayAdjList(struct List** adjList, int V) {
    for (int i = 0; i < V; i++) {
        printf("Vertex %c: ", i + 'A'); 
        struct Node* curr = adjList[i]->head;
        while (curr) {
            printf("[%c, %d] -> ", curr->vertex, curr->weight);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}
void createEdge(struct List** adjList, int src, int dst, int weight, int edgeType) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dst + 'A';
    newNode->weight = weight;
    newNode->next = NULL;
    if (adjList[src]->head == NULL) {
        adjList[src]->head = newNode;
    } else {
        adjList[src]->tail->next = newNode;
    }
    adjList[src]->tail = newNode;
    
    if (edgeType == 0) { // Create a bidirectional edge if edgeType is 0
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = src + 'A';  
        newNode->weight = weight;
        newNode->next = NULL;
        if (adjList[dst]->head == NULL) {
            adjList[dst]->head = newNode;
        } else {
            adjList[dst]->tail->next = newNode;
        }
        adjList[dst]->tail = newNode; 
    }
}
struct List** createGraph(int V, int E){
    char src, dst; 
    int weight, graphtype;
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
        printf("Enter Src and Dst and Weight of Edge %d: ", i + 1);
        getchar();  // To consume newline character left by previous scanf
        scanf("%c %c", &src, &dst, &weight);
        createEdge(adjList, src - 'A', dst - 'A', weight, graphtype);
    }
    return adjList;
}