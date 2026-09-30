#include <stdio.h>

void reverse(int *start, int *end) {
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int a[100], n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    reverse(a, a + n - 1);

    printf("The reversed array is:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}