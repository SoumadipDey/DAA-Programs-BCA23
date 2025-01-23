#include <stdio.h>
void merge(int arr[], int l, int m, int h) {
	int i,j,k = l;
  	int n1 = m - l + 1;
  	int n2 = h - m;
	int L[n1], M[n2];
  	for (i = 0; i < n1; i++){
    		L[i] = arr[l + i];
    }
  	for (j = 0; j < n2; j++){
    		M[j] = arr[m + 1 + j];
    }	
	i = 0;j = 0;
  	while (i < n1 && j < n2) {
    		if (L[i] <= M[j]) {
      			arr[k++] = L[i++];
    		} else {
      			arr[k++] = M[j++];
    		}
  	}
  	while (i < n1) {
    		arr[k++] = L[i++];
  	}
  	while (j < n2) {
    		arr[k++] = M[j++];
  	}
}

void mergeSort(int l, int h, int arr[]) {
  	if (l < h) {
    		int m = l + (h - l) / 2;
    		mergeSort(l, m, arr);
    		mergeSort(m + 1, h, arr);
    		merge(arr, l, m, h);
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
	mergeSort(0,n-1,arr);
	printf("The sorted array: ");
	for(i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
