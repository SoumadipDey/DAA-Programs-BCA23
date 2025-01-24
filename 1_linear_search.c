#include <stdio.h>
int linearSearch(int arr[], int n, int key){
    int status = -1;
    for (int i = 0; i < n; i++){
        if(arr[i] == key){
            status = i;
        }
    }
    return status;
}

int main(){
    int n, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you are searching for: ");
    scanf("%d", &key);
    int pos = linearSearch(arr,n,key);
    if(pos != -1){
        printf("Element found at index: %d", pos);
    } else {
        printf("Element not found!");
    }
    return 0;
}
