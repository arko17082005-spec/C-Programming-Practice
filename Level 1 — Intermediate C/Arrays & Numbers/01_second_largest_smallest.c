#include <stdio.h>

int main() {
    int a[100], n, i;
    int largest, secondLargest, smallest, secondSmallest;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter number of elements: ");
    for (i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    largest = secondLargest = a[0];
    smallest = secondSmallest =a[0];

    for (i=1;i<n;i++) {
        if (a[i]>largest) {
            secondLargest = largest;
            largest =a[i];
        } else if (a[i] > secondLargest && a[i] != largest) {
            secondLargest = a[i];
        }

        if (a[i] < smallest) {
            secondSmallest = smallest;
            smallest = a[i];
        } else if (a[i] < secondSmallest && a[i] != smallest) {
            secondSmallest = a[i];
        }
    }

    printf("\nSecond Largest = %d", secondLargest);
    printf("\nSecond Smallest = %d", secondSmallest);

    return 0;
}
