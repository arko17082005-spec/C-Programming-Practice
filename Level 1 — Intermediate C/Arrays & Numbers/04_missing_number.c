#include <stdio.h>
int main() {
    int a[100], n, i;
    int sum = 0, expectedSum, missing;
    printf("Enter N: ");
    scanf("%d",&n);
    printf("Enter %d numbers: \n", n-1);
    for(i=0;i<n-1;i++) {
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    expectedSum=n*(n+1)/2;
    missing = expectedSum-sum;
    printf("Missing number = %d\n", missing);
    return 0;
}