#include <stdio.h>
void heapify(int n,int arr[], int i){
	int l,r,t,max = i;
	l = 2*i + 1;
	r = 2*i + 2;
	if(l < n && arr[l] > arr[max]){
		max = l;
	}
	if(r < n && arr[r] > arr[max]){
		max = r;
	}
	if(max != i){
		t = arr[i];
		arr[i] = arr[max];
		arr[max]= t;
		
		heapify(n,arr,max);
	}
}
void heapSort(int arr[], int n){
	int t,i;
	for(i = n/2 - 1; i >= 0 ; i--){
		heapify(n,arr,i);
	}
	for(i = n-1; i >= 0 ; i--){
		t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		
		heapify(i,arr,0);	
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
	heapSort(arr,n);
	printf("The sorted array: ");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
