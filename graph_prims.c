#include "graph.c"
#define INFINITY __INT_MAX__

struct Edge{
    char src;
    char dst;
    int weight;
};

struct Edge findMinEdge(struct List** adjList, int V){
    int curr_index = -1, min_weight = INFINITY;
    struct Edge min_edge;
    struct Node* neighbour; 
    for (int i = 0; i < V; i++){
        curr_index = i;
        neighbour = adjList[curr_index]->head;
        while(neighbour){
            if(neighbour->weight < min_weight){
                min_edge.src = i + 'A';
                min_edge.dst = neighbour->vertex;
                min_edge.weight = neighbour->weight;
                min_weight = min_edge.weight;
            }
            neighbour = neighbour->next;
        }
    }
    return min_edge;
}

void primsMST(struct List** adjList, int V){
    int visited[V], predecessor[V];

}

int main(){
    int V,E;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V,E);
    struct Edge min_edge = findMinEdge(adjList, V);
    printf("The minimum edge is: %C ---%d---> %C", min_edge.src, min_edge.weight, min_edge.dst);
    return 0;
}