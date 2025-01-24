#include <stdio.h>
int binSearch(int arr[],int high, int low, int key){
	int mid;
	if(low <= high){
		mid = (high + low)/2;
		if(arr[mid] == key){
			return mid;
		} else if(arr[mid] < key) {
			return binSearch(arr,high,mid+1,key);
		} else {
			return binSearch(arr,mid-1,low,key);
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
	res = binSearch(arr,n-1,0,key);
	if(res != -1){
		printf("The element was found at index: %d\n",res);
	} else {
		printf("The element was not found!\n");
	}
	return 0;	
}
