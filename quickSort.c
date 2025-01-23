#include <stdio.h>
int partition(int array[], int low, int high) {
  	int pivot = array[high];
  	int i = (low - 1);
  	int temp;
  	for (int j = low; j < high; j++) {
    		if (array[j] <= pivot) {
      			i++;
      			temp = array[i];
      			array[i] = array[j];
      			array[j] = temp;
    		}
  	}
  	temp = array[i + 1];
  	array[i + 1] = array[high];
  	array[high] = temp;
  	return (i + 1);
}

void quickSort(int array[], int low, int high) {
  	if (low < high) {
    		int pi = partition(array, low, high);
    		quickSort(array, low, pi - 1);
    		quickSort(array, pi + 1, high);
  	}
}
int main(){
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,n-1);
	printf("The sorted array: ");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
