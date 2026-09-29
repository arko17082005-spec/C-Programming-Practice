#include <stdio.h>
int main() {
    int a[100], n, i;
    int currentSum, maxSum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    currentSum = maxSum = a[0];

    for (i=1;i<n;i++){
        if(currentSum + a[i] > a[i]){
            currentSum = currentSum + a[i];
        }else{
            currentSum = a[i];
        }
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    printf("Maximum subarray sum = %d \n", maxSum);
    return 0;
}