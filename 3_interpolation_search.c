#include <stdio.h>
int interpSearch(int arr[], int low, int high, int key){
	int mid;
	if(low <= high && key >= arr[low] && key <= arr[high]){
		mid = low + (high-low)*((float)(key - arr[low])/(arr[high] - arr[low]));
		if(arr[mid] == key){
			return mid;
		} else if(key > arr[mid]) {
			return interpSearch(arr, mid + 1, high, key);
		} else {
			return interpSearch(arr, low, mid-1,key);
		}
	}
	return -1;
}
int main(){
	int n,key,i,res;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements in ascending order: ",n);
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the search/key element: ");
	scanf("%d",&key);
	res = interpSearch(arr,0,n-1,key);
	if(res != -1){
		printf("The element was found at index: %d\n",res);
	} else {
		printf("The element was not found!\n");
	}
	return 0;	
}
