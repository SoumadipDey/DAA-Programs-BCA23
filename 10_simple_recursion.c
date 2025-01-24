#include <stdio.h>
/*  a. Calculate the factorial of a given number.
    b. Calculate the sum of digits of a number.
    c. Convert a given decimal number to binary.
*/
int recursiveFactorial(int n){
    return ((n == 0)||(n == 1))? 1: n * recursiveFactorial(n - 1);
}
int recursiveSumDigits(int n){
    return (n == 0)? 0 : ((n % 10) + recursiveSumDigits(n/10));
}
int recursiveBinaryConvert(int n){
    return ((n == 0)||(n == 1))? n: ((n % 2) + 10 * recursiveBinaryConvert(n/2));
}
int main(){
    int choice, n;
    do{
        printf("Enter your choice: \n1. Calculate the factorial of a given number.\n2. Calculate the sum of digits of a number.\n3. Convert a given decimal number to binary.\n Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the number: ");
                scanf("%d",&n);
                printf("The factorial of %d is: %d\n", n, recursiveFactorial(n));
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d",&n);
                printf("The sum of digits of %d is: %d\n", n, recursiveSumDigits(n));
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d",&n);
                printf("The binary form of %d is: %d\n", n, recursiveBinaryConvert(n));
                break;
            case -1:
                break;
            default: 
                printf("Wrong Choice!\n");
                break;
        }
    } while(choice != -1);
    return 0;
}
