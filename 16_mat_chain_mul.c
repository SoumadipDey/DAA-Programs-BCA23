#include <stdio.h>
#define INT_MAX __INT32_MAX__
int n; // Keeping n as a global for ease of use.
int MCM(int dims[], int i, int j, int mat[n - 1][n - 1]){
    if (mat[i][j] == -1){
        if(i == j) mat[i][j] = 0;
        else{
            int min = INT_MAX, cost;
            for (int k = i; k < j; k++){
                cost = MCM(dims, i, k, mat) + MCM(dims, k+1, j, mat) + dims[i]*dims[k+1]*dims[j+1]; 
                if(cost < min){
                    min = cost;
                }
            }
            mat[i][j] = min;
        }
    }
    return mat[i][j];
}
int main(){
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    int dims[n + 1], mat[n][n];
    printf("Enter the Rows and Columns of each matrix\n");
    for (int i = 0; i < n; i++){
        printf("Matrix %d: ", i + 1);
        scanf("%d %d",&dims[i], &dims[i+1]);
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = -1;
        }
    }
    int result = MCM(dims, 0, n - 1, mat);
    printf("The minimum number of multiplication required is: %d", result);
    return 0;
}