#include "graph.c"
#include <string.h>

void DFSTraverse(struct List** adjList, int start, int* visited){
    struct Node* curr = adjList[start]->head; // Check the first neighbour of the start node
    while(curr != NULL){ // Continue checking all the neighbours till no neighbours are left
        int index_curr = curr->vertex - 'A'; 
        if(visited[index_curr] != 1){ //If the current neighbour is not already visited then visit it
            printf("%c --> ", curr->vertex);
            visited[index_curr] = 1; 
            DFSTraverse(adjList, index_curr, visited);
        }
        curr = curr->next;
    }
}
void DFS(struct List** adjList,int V){
    int visited[V], counter = 1;
    memset(visited, 0, sizeof(visited));
    for (int start = 0; start < V; start++){
        if (visited[start] != 1){
            printf("DFS Traversal of Component %d: ", counter);
            printf("%c --> ", start + 'A');
            visited[start] = 1; // Mark the start node as visited
            DFSTraverse(adjList, start, visited);
            printf("End\n");
            counter++;
        }
    }
}

void BFS(struct List** adjList, int V){
    int visited[V], front, rear, counter = 1;
    int queue[V];
    for (int i = 0; i < V; i++) {visited[i] = 0;} // Initialize all nodes unvisited
    for (int start = 0; start < V; start++){
        if (!visited[start]){
            front = rear = 0;
            queue[rear] = start;
            visited[start] = 1; // Mark the start node as visited
            printf("BFS Traversal of Component %d: ", counter);
            
            while (front <= rear) {
                int currIndex = queue[front++]; // Dequeue the start node
                printf("%c --> ", currIndex + 'A');

                // Check the first neighbour of the start node
                struct Node* curr = adjList[currIndex]->head; 
                while (curr) { // Add all neighbours of the start node to the queue
                    int neighborIndex = curr->vertex - 'A';
                    if (!visited[neighborIndex]) {

                        // Premark the neighbours as visited to avoid redundancy in queue
                        visited[neighborIndex] = 1;  
                        queue[++rear] = neighborIndex; // Enqueue
                    }
                    curr = curr->next;
                }
            }
            printf("End\n");
            counter++;
        }
    }
}

int main(){
    int V,E;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V,E);
    printf("The DFS of the given graph is as follows: \n");
    DFS(adjList,V);
    printf("The BFS of the given graph is as follows: \n");
    BFS(adjList,V);
}