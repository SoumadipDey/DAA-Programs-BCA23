#include <stdio.h>
#include <string.h>
#define INT_MAX 9999
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
void primSpanningTree(int n,int adj[n+1][n+1],char vertices[n]){
    int visited[n],total_cost = 0;
    memset(visited, 0, n*sizeof(visited[0]));
    visited[0] = 1;
    int count = 0;
    printf("\nPrims MST: \n");
    while (count < n - 1){
        int min = INT_MAX,x,y;
        for (int i = 1; i < n+1; i++){
            if(visited[i-1]){
                for (int j = 1; j < n+1; j++){
                    if((visited[j-1] == 0) && (adj[i][j] != 0) && (adj[i][j] != -1)){
                        if(min > adj[i][j]){
                            min = adj[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%c <-> %c : %d\n",vertices[x-1],vertices[y-1],adj[x][y]);
        total_cost += adj[x][y];
        visited[y-1] = 1;
        count++;
    }
    printf("The total cost of MST = %d\n",total_cost);
}
int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int adj[n+1][n+1];
    char vertices[n];
    printf("The vertices are: ");
    for (int i = 0; i < n; i++){
        vertices[i] = 65 + i;
        adj[0][i+1] = vertices[i];
        adj[i+1][0] = vertices[i];
        printf("%c ",vertices[i]);
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
    primSpanningTree(n,adj,vertices);
    return 0;
}