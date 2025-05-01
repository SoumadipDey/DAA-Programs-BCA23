#include <stdio.h>
struct Item{
    int id;
    int value;
    int weight;
    int status;
};
int solveBinaryKnapsack(struct Item items[], int n, int maxCap, int dp[n + 1][maxCap + 1]){
    // Calculate maximum obtainable value through dp;
    int newVal;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxCap; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j]; // Initially keep current element unselected
                /* Find out the updated profit of selecting the current element in
                   the current arrangement*/
                newVal =  dp[i-1][j - items[i].weight] + items[i].value;
                if((j >= items[i].weight) && (newVal > dp[i][j])){
                    /* If the current selection is valid and greater than the previous
                       selection then update the dp table value accordingly*/
                    dp[i][j] = newVal;
                }
            }
        }
    }
    // Mark selected elements
    int i = n, j = maxCap;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i - 1][j]){
            items[i].status = 1;
            j -= items[i].weight;
        }
        i -= 1;
    }
    return dp[n][maxCap];
}
int main(){
    int n, capacity;
    printf("Enter the number of items and capacity of knapsack: ");
    scanf("%d %d",&n, &capacity);

    // Making everything 1-based indexed to make things easy
    struct Item items[n + 1];
    int dp[n + 1][capacity + 1];

    //Taking inputs and initializing
    printf("Enter the weight and value of %d items:\n",n);
    for (int i = 1; i <= n; i++){
        printf("Item %d :", i);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].id = i;
        items[i].status = 0;
    }
    printf("Max Value obtained is : %d\n", solveBinaryKnapsack(items, n, capacity, dp));
    printf("The selected items are: { ");
    for (int i = 1; i <= n; i++){
        if(items[i].status != 0){
            printf("Item[%d] (W:%d V:%d) ", items[i].id, items[i].weight, items[i].value);
        }
    } printf("}\n");

    printf("The DP Table: \n");
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= capacity; j++){
            printf("%5d ", dp[i][j]);
        }
        printf("\n");    
    }
    
    return 0;
}