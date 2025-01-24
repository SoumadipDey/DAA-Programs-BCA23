#include <stdio.h>
void selectionSort(int n,int arr[n]){
	int temp,i,j,min;
	for(i = 0; i < n; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[min]){
				min = j;	
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main(){
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements: ",n);
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	selectionSort(n,arr);
	printf("The Selection Sorted Array: ");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
