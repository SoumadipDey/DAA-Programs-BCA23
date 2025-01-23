#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void customSort(int jobs[], int profit[], int deadline[], int n){
    //Sorting based on deadlines ascending
    float temp;
    int i,min;
	for(i = 0; i < n; i++){
		min = i;
		for(int j = i + 1; j < n; j++){
			if(profit[j] > profit[min]){
				min = j;	
			}
		}
        swap(&deadline[i],&deadline[min]);
        swap(&profit[i],&profit[min]);
        swap(&jobs[i],&jobs[min]);
	}
}
void printTabular(int jobs[],int profit[],int deadline[],int status[],int n){
    printf("\nJob\tProfit\tDeadline\tStatus\n");
    for (int i = 0; i < n; i++){
        printf("%4d \t%4d \t%4d \t\t%4d\n",jobs[i],profit[i],deadline[i],status[i]);
    }
}
int main(){
    int n, total_profit = 0;
    printf("Enter the total number of jobs: ");
    scanf("%d",&n);
    int max_deadline = n;
    int jobs[n],profit[n],deadline[n],status[n];
    printf("Enter the profit and deadline: \n");
    for (int i = 0; i < n; i++){
        scanf("%d %d",&profit[i],&deadline[i]);
        jobs[i] = i + 1;
        status[i] = 0;
    }
    customSort(jobs,profit,deadline,n);
    int curr = 1;
    for (int i = 0; i < n; i++){
        if(deadline[i] >= curr){
            total_profit += profit[i];
            status[i] = 1;
            curr++;
        }
    }
    printf("The solution of the job sequencing problem: \n");
    printTabular(jobs,profit,deadline,status,n);
    printf("Total profit of solution: %d\n",total_profit);
    return 0;
}