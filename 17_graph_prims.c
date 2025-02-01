#include "graph.c"
#define INFINITY __INT_MAX__
struct Edge{
    char src;
    char dst;
    int weight;
};
struct Edge findMinValidEdgeFromSource(struct List** adjList, int visited[], int src){
    int min_weight = INFINITY;
    struct Edge min_edge;
    min_edge.src = src + 'A';
    min_edge.dst = '\0';
    
    struct Node* neighbour;
    neighbour = adjList[src]->head;
    while(neighbour){
        if(neighbour->weight < min_weight && !visited[neighbour->vertex - 'A']){
            min_edge.dst = neighbour->vertex;
            min_weight = neighbour->weight;
            min_edge.weight = min_weight;
        }
        neighbour = neighbour->next;
    }
    return min_edge;
}

void primsMST(struct List** adjList, int V){
    int visited[V], edge_count = 0, cost = 0;
    for (int i = 0; i < V; i++){
        visited[i] = 0;
    }
    struct Edge edge, min_edge;
    visited[0] = 1; // We choose the 1st node as the arbitary starting node
    while (edge_count < V - 1){ // Since a MST can have a maximum of V - 1 edges.
        min_edge.src = min_edge.dst = '\0';
        min_edge.weight = INFINITY;
        for (int i = 0; i < V; i++){
            // Find the minimum non-cyclic edge connected to the visited nodes.
            if(visited[i]){
                edge = findMinValidEdgeFromSource(adjList, visited, i);
                if(edge.dst != '\0' && edge.weight < min_edge.weight){
                    min_edge = edge;
                }
            }   
        }
        if(min_edge.dst == '\0'){ // Early return if any node is isolated!
            printf("Graph is Disconnected. No MST!\n");
            return;
        } 
        // Else print the currently selected edge and mark its destination as visited
        printf("Selected %c ---%d---> %c\n", min_edge.src, min_edge.weight, min_edge.dst);
        visited[min_edge.dst - 'A'] = 1;
        cost += min_edge.weight;
        edge_count++;
    }
    printf("Cost of the MST is: %d\n", cost);
}

int main(){
    int V,E;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V,E);
    printf("The result of running Prim's MST Algorithm on the given graph is:\n");
    primsMST(adjList,V);
    return 0;
}