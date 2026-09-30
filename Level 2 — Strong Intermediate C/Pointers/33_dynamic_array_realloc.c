#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a;
    int n, newSize, i;

    printf("Enter initial size: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter new size: "); 
    scanf("%d", &newSize);

    a=(int *)realloc(a, newSize * sizeof(int));

    if (a==NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    if (newSize > n) {
        printf("Enter %d new elements:\n", newSize - n);
        
        for (i = n; i < newSize; i++) {
            scanf("%d", &a[i]);
        }
    }

    printf("Array after resizing:\n");

    for (i = 0; i < newSize; i++) {
        printf("%d ", a[i]);
    }

    free(a);

    return 0;
}