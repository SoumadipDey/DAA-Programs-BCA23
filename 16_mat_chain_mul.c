#include <stdio.h>
#define INT_MAX __INT32_MAX__
int n; // Keeping n as a global for ease of use.
int MCM(int dims[], int i, int j, int mat[n - 1][n - 1], int grp[n - 1][n - 1]){
    if (mat[i][j] == -1){
        if(i == j) mat[i][j] = 0;
        else{
            int min = INT_MAX, cost;
            for (int k = i; k < j; k++){
                cost = MCM(dims, i, k, mat, grp) + 
                       MCM(dims, k+1, j, mat, grp) + 
                       dims[i]*dims[k+1]*dims[j+1]; 
                if(cost < min){
                    min = cost;
                    grp[i][j] = k;
                }
            }
            mat[i][j] = min;  
        }
    }
    return mat[i][j];
}
void printOptimalOrder(int i, int j, int grp[n - 1][n - 1]){
    if(i == j) printf("A%d ", i + 1);
    else{
        printf("(");
        int k = grp[i][j];
        printOptimalOrder(i, k, grp);
        printf(" x ");
        printOptimalOrder(k+1, j, grp);
        printf(")");
    }
}
int main(){
    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    int dims[n + 1], mat[n][n], grp[n][n];
    printf("Enter the Rows and Columns of each matrix\n");
    for (int i = 0; i < n; i++){
        printf("Matrix %d: ", i + 1);
        scanf("%d %d",&dims[i], &dims[i+1]);
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = -1;
            grp[i][j] = -1;
        }
    }
    int result = MCM(dims, 0, n - 1, mat, grp);
    printf("The minimum number of multiplication required is: %d", result);
    printf("\nOptimal Parenthesization: \n");
    printOptimalOrder(0, n - 1, grp);
    return 0;
}