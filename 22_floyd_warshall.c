#include "graph.c"
#define INFINITY __INT_MAX__

void printMatrix(int V, int mat[V][V]){
    printf("     ");
    for (int i = 0; i < V; i++){
        printf("%3c ", i + 'A');        
    } printf("\n");
    for (int i = 0; i < V; i++){
        printf("%3c: ", i + 'A');
        for (int j = 0; j < V; j++){
            if(mat[i][j] == INFINITY) printf("INF ");
            else printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}
void findAllPairShortestPath(struct List** adjList, int V){
    // Creating the initial adjacency Matrix
    int A[V][V], newDist;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            A[i][j] = (i == j) ? 0: INFINITY;
        }
    }
    struct Node* neighbour;
    for (int i = 0; i < V; i++){
        neighbour = adjList[i]->head;
        while (neighbour) {
            A[i][neighbour->vertex - 'A'] = neighbour->weight;
            neighbour = neighbour->next;
        }
    }
    // Calculating all pair shortest paths
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if(i == j && (i == k || j == k)) continue;
                else {
                    newDist = (A[i][k] == INFINITY || A[k][j] == INFINITY)? INFINITY : A[i][k] + A[k][j];
                    if(newDist < A[i][j]){
                        A[i][j] = newDist;
                    }
                }
            }
        }
    }
    // Printing the all pair shortest distance matrix
    printMatrix(V, A);
}
int main(){
    int V, E;
    printf("Enter the Number of Vertices in the Graph: ");
    scanf("%d", &V);
    printf("Enter the Number of Edges in the Graph: ");
    scanf("%d", &E);
    struct List** adjList = createGraph(V, E);
    printf("The result of running Floyd Warshall Algorithm:\n");
    findAllPairShortestPath(adjList, V);
    return 0;
}
