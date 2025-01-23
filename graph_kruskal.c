#include <stdio.h>
#include <string.h>
#define INT_MAX 9999
struct Edge{
    char v1,v2;
    int x,y;
    int weight;
};
struct Edge findCurrMinEdge(int n,int adj_cpy[n+1][n+1],int visited[n]){
    struct Edge e;
    int min = INT_MAX;
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            if(!((visited[i-1] == 1) && (visited[j-1]) == 1)){
                if ((adj_cpy[i][j] != 0) && (adj_cpy[i][j] != -1)){
                    if(adj_cpy[i][j] < min){
                        min = adj_cpy[i][j];
                        e.weight = min;
                        e.v1 = adj_cpy[0][i];
                        e.v2 = adj_cpy[j][0];
                        e.x = i;
                        e.y = j;
                    }
                }
           } 
        }
    }
    return e;
}
void matrixCopy(int n,int dest[n+1][n+1],int src[n+1][n+1]){
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
            dest[i][j] = src[i][j];
        }
    }
}
void kruskalSpanningTree(int n, int adj[n+1][n+1]){
    int adj_cpy[n+1][n+1],visited[n],n_edge = 0,total_cost = 0;
    memset(visited, 0, n*sizeof(visited[0]));
    matrixCopy(n,adj_cpy,adj);
    struct Edge e;
    printf("\nKruskal's MST:\n");
    while (n_edge < n-1){
        e = findCurrMinEdge(n,adj_cpy,visited);
        adj_cpy[e.x][e.y] = -1;
        visited[e.x-1] = 1;
        visited[e.y-1] = 1;
        printf("%c <-> %c : %d\n",e.v1,e.v2,adj[e.x][e.y]);
        total_cost += e.weight;
        n_edge++;
    }
    printf("The total cost = %d\n",total_cost);
}
void viewAjdMatrix(int n,int adj[n+1][n+1]){
    printf("\nThe adjacency matrix: \n");
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++){
            if((i == 0) || (j == 0)){
                if(i == j){
                    printf(" \\ ");
                } else {
                    printf("%2c ",adj[i][j]);
                }
            } else {
                printf("%2d ",adj[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int adj[n+1][n+1];
    printf("The vertices are: ");
    for (int i = 0; i < n; i++){ 
        adj[0][i+1] = 65 + i;
        adj[i+1][0] = 65 + i;
        printf("%c ",adj[0][i+1]);
    }
    printf("\nEnter all the edges: \n");
    /*  Enter -1 for not connected edges.
        For others enter positive integers.
    */
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < n+1; j++){
            if(i < j){
                printf("Weight of edge %c <-> %c : ",adj[i][0],adj[0][j]);
                scanf("%d",&adj[i][j]);
                adj[j][i] = adj[i][j];
            } else if(i == j){
                adj[i][j] = 0;
            }
        }
    }
    viewAjdMatrix(n,adj);
    kruskalSpanningTree(n,adj);
    return 0;
}