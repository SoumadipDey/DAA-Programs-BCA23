#include <stdio.h>
int mid;
int interpSearch(int arr[],int high, int low, int key){
	if(low <= high){
		mid = low + (high-low)*((float)(key - arr[low])/(arr[high] - arr[low]));
		if(arr[mid] == key){
			return mid;
		} else if(key > arr[mid]) {
			return interpSearch(arr,high,mid+1,key);
		} else {
			return interpSearch(arr,mid-1,low,key);
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
	res = interpSearch(arr,n-1,0,key);
	if(res != -1){
		printf("The element was found at index: %d\n",res);
	} else {
		printf("The element was not found!\n");
	}
	return 0;	
}
