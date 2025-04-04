#include <stdio.h>
#define INT_MAX __INT32_MAX__
int MCM(int dims[], int n, int i, int j, int mat[n - 1][n - 1]){
    if (mat[i][j] == -1){
        if(i == j) mat[i][j] = 0;
        else{
            int min = INT_MAX, cost;
            for (int k = i; k < j; k++){
                cost = MCM(dims, n, i, k, mat) + MCM(dims, n, k+1, j, mat) + dims[i]*dims[k+1]*dims[j+1]; 
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
    /* code */
    return 0;
}