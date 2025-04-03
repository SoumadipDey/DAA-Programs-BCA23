#include <stdio.h>
struct Item{
    int id;
    int  itemWeight;
    int itemValue;
    float valueByWeight;
    float status;
};
void swap(struct Item* a, struct Item* b){
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void itemSort(struct Item items[], int n){
    int max;
	for(int i = 0; i < n - 1; i++){
		max = i;
		for(int j = i + 1; j < n; j++){
			if(items[j].valueByWeight > items[max].valueByWeight){
				max = j;	
			}
		}
        swap(&items[i],&items[max]);
	}
}
float fractionalKnapsack(struct Item items[], int n, int max_capacity){
    int capacity = max_capacity, i = 0;
    float totalValue = 0;
    while (i < n && capacity > 0){
        if(capacity - items[i].itemWeight >= 0){ // No fraction needed
            capacity -= items[i].itemWeight;
            items[i].status = 1.0;
            totalValue += items[i].status * items[i].itemValue;
        } else {
            if(capacity < items[i].itemWeight){ // Fraction needed
                items[i].status = (float) capacity / items[i].itemWeight;
                capacity = 0;
                totalValue += items[i].status * items[i].itemValue;
            }
        }
        i++;
    }
    return totalValue;
}
void printTabular(struct Item items[] , int n){
    printf("\nItem\tWeight\tValue\tRatio\tStatus\n");
    for (int i = 0; i < n; i++){
        struct Item curr = items[i];
        printf("Item %d \t%4d \t%4d \t%2.2f \t%2.2f\n", curr.id, curr.itemWeight, curr.itemValue, curr.valueByWeight, curr.status);
    }
}
int main(){
    int n, capacity;
    printf("Enter the number of items and capacity of knapsack: ");
    scanf("%d %d",&n, &capacity);
    struct Item items[n];

    //Taking inputs and initializing
    printf("Enter the weight and value of %d items:\n",n);
    for (int i = 0; i < n; i++){
        printf("Item %d :", i + 1);
        scanf("%d %d", &items[i].itemWeight, &items[i].itemValue);
        items[i].valueByWeight = (float) items[i].itemValue / items[i].itemWeight;
        items[i].id = i + 1;
        items[i].status = 0;
    }
    
    itemSort(items, n);
    float total_value = fractionalKnapsack(items, n, capacity);
    
    printf("The Solution for the fractional Knapsack Problem: ");
    printTabular(items, n);
    printf("\nTotal Value: %.2f\n",total_value);
    return 0;
}