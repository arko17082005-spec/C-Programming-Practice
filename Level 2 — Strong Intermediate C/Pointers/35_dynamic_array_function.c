#include <stdio.h>
#include <stdlib.h>

int *createArray(int n) {
    int *arr;
    int i;

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        arr[i] = 0;
    }

    return arr;
}

int main() {
    int *a;
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    a = createArray(n);

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Dynamically allocated array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}