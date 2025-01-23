#include <stdio.h>
void insertionSort(int n,int arr[n]){
	int i,j,val;
	for(i = 1; i < n; i++){
		val = arr[i];
		j = i - 1;
		while((val < arr[j]) && (j >= 0)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
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
	insertionSort(n,arr);
	printf("The Insertion Sorted Array: ");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
