#include "graph.c"
struct Edge {
    char src;
    char dst;
    int weight;
};

struct EdgeData {
    struct Edge* edgeList;
    int size;
};

struct EdgeData createSortedEdgeList(struct List** adjList, int V, int E, int graph_type) {
    //Creating an empty edge list
    struct Edge* edgeList = NULL;
    struct EdgeData edgeData;
    if(graph_type != 0){ 
        edgeList = (struct Edge*)malloc(E * sizeof(struct Edge));
        edgeData.size = E;  
    } else { 
        edgeList = (struct Edge*)malloc(2 * E * sizeof(struct Edge));
        edgeData.size = 2 * E;
    }
    //Populating the empty edge list with edges from the adjacency list
    struct Node* neighbour;
    int edge_index = 0;
    for (int i = 0; i < V; i++) {
        neighbour = adjList[i]->head;
        while (neighbour) {
            edgeList[edge_index].src = i + 'A';
            edgeList[edge_index].dst = neighbour->vertex;
            edgeList[edge_index].weight = neighbour->weight;
            neighbour = neighbour->next;
            edge_index++;
        }
    }
    //Sorting the edge list based on weights using selection sort
    for (int i = 0; i < edgeData.size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < edgeData.size; j++) {
            if (edgeList[j].weight < edgeList[min_index].weight) {
                min_index = j;
            }
        }
        struct Edge temp = edgeList[i];
        edgeList[i] = edgeList[min_index];
        edgeList[min_index] = temp;
    }
    edgeData.edgeList = edgeList;
    return edgeData;
}

void kruskalMST(struct List** adjList, int V, int E, int graph_type) {
    int component[V], edge_count = 0, cost = 0 , srcComp, dstComp;
    for (int i = 0; i < V; i++){ // Initially every vertex is its own component
        component[i] = i;
    }
    // Creating a sorted edge list
    struct EdgeData edgeData = createSortedEdgeList(adjList, V, E, graph_type);
    struct Edge* edgeList = edgeData.edgeList;
    struct Edge curr_edge;
    int edge_index = 0;
    while (edge_count < V - 1) {
        curr_edge = edgeList[edge_index];
        srcComp = component[curr_edge.src - 'A'];
        dstComp = component[curr_edge.dst - 'A'];
        // Check if the current edge does not form a cycle
        if(srcComp != dstComp){ 
            cost += curr_edge.weight;
            printf("Selected %c ---%d---> %c\n", curr_edge.src, curr_edge.weight, curr_edge.dst);
            // Cascadingly merge the components of the src and dst vertices
            for (int i = 0; i < V; i++) {
                if (component[i] == srcComp) {
                    component[i] = dstComp;
                }
            }
            edge_count++;   
        }
        if(edge_index >= edgeData.size) {
            printf("Graph is Disconnected. No MST!\n");
            return;
        }
        edge_index++;
    }
    printf("Cost of the MST is: %d\n", cost);
}

int main() {
    int V, E;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V, E);
    int graph_type = adjList[0]->type; // Fetching the graph type
    printf("The result of running Kruskal's MST Algorithm on the given graph is:\n");
    kruskalMST(adjList, V, E, graph_type);
    return 0;
}