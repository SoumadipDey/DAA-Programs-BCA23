#include "graph.c"

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
    for (int start = 0; start < V; start++){
        if (visited[start] != 1){
            printf("DFS Traversal of Component %d: ", counter);
            printf("%c --> ", start + 'A');
            visited[start] = 1; // Marl the start node as visited
            DFSTraverse(adjList, start, visited);
            printf("End\n");
            counter++;
        }
    }
}
/* 
void BFS(struct List** adjList, int V){
    int visited[V], front, rear, counter = 1;
    struct Node* queue[V];
    for (int start = 0; start < V; start++){
        if (visited[start] != 1){
            front = rear = -1;
            printf("BFS Traversal of Component %d: ", counter);
            printf("%c --> ", start + 'A');
            visited[start] = 1; // Mark the start node as visited
            front = rear = 0;
            queue[rear] = adjList[start]->head;
            while(front <= rear){
                struct Node* curr = queue[front];
                if(visited[queue[front]->vertex - 'A'] != 1){
                    visited[curr->vertex - 'A'] = 1;
                    front++;
                    printf("%c -->", curr->vertex);
                    while (curr != NULL){
                        rear++;
                        queue[rear] = curr;
                        curr = curr->next;
                    }   
                }
            }
            printf("End\n");
            counter++;
        }
    }
}
*/
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