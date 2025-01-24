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
    for (int i = 0; i < V; i++){
        if (visited[i] != 1){
            printf("DFS Traversal of Component %d: ", counter);
            printf("%c --> ", i + 'A');
            visited[i] = 1;
            DFSTraverse(adjList, i, visited);
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
}