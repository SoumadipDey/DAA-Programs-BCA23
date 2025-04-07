#include "graph.c"
#define INFINITY __INT_MAX__
struct Edge {
    char src;
    char dst;
    int weight;
    int used;
};

struct Edge* createEdgeList(struct List** adjList, int V, int E, int graph_type) {
    int edge_index = 0;
    struct Edge* edgeList = (struct Edge*)malloc(E * sizeof(struct Edge));
    struct Node* neighbour;

    for (int i = 0; i < V; i++) {
        neighbour = adjList[i]->head;
        while (neighbour) {
            //Consider undirected edges only once.
            if (graph_type == 0 && i + 'A' > neighbour->vertex) {
                neighbour = neighbour->next;
                continue;
            }

            edgeList[edge_index].src = i + 'A';
            edgeList[edge_index].dst = neighbour->vertex;
            edgeList[edge_index].weight = neighbour->weight;
            edgeList[edge_index].used = 0;
            neighbour = neighbour->next;
            edge_index++;
        }
    }
    return edgeList;
}

struct Edge findMinValidEdge(struct Edge* edgeList, int visited[], int E, int graph_type) {
    int src_index, dst_index, min_index = -1;
    struct Edge min_edge;
    min_edge.src = min_edge.dst = '\0';
    min_edge.weight = INFINITY;

    for (int i = 0; i < E; i++) { 
        src_index = edgeList[i].src - 'A';
        dst_index = edgeList[i].dst - 'A';
        if (!edgeList[i].used && (!visited[src_index] || !visited[dst_index])) {
            if (edgeList[i].weight < min_edge.weight) {
                min_index = i;
                min_edge = edgeList[i];
            }
        }
    }

    if (min_index != -1) {
        edgeList[min_index].used = 1;
    }

    return min_edge;
}

void kruskalMST(struct List** adjList, int V, int E, int graph_type) {
    int visited[V], edge_count = 0, cost = 0;
    for (int i = 0; i < V; i++) visited[i] = 0;
    struct Edge* edgeList = createEdgeList(adjList, V, E, graph_type);
    struct Edge curr_edge;

    while (edge_count < V - 1) {
        curr_edge = findMinValidEdge(edgeList, visited, E, graph_type);
        //if (curr_edge.dst == '\0') {
            //printf("Graph is Disconnected. No MST!\n");
            //return;
        //}
        visited[curr_edge.src - 'A'] = visited[curr_edge.dst - 'A'] = 1;
        cost += curr_edge.weight;
        printf("Selected %c ---%d---> %c\n", curr_edge.src, curr_edge.weight, curr_edge.dst);
        edge_count++;
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