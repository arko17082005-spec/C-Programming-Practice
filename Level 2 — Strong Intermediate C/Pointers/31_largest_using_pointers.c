#include <stdio.h>

int main() {
    int a[100],n, i; 
    int *p;
    int largest;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    p = a;
    largest = *p;

    for (i=1;i<n;i++) {
        if (*(p+i) > largest) {
            largest = *(p+i);
        }
    }
    printf("The largest element is: %d\n", largest);
    return 0;
}