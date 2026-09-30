#include <stdio.h>

void generateSubsets(int a[], int n, int index, int subset[], int size) {
    int i;

    if (index == n) {
        printf("{ ");

        for (i = 0; i < size; i++) {
            printf("%d ", subset[i]);
        }

        printf("}\n");
        return;
    }

    generateSubsets(a, n, index + 1, subset, size);

    subset[size] = a[index];

    generateSubsets(a, n, index + 1, subset, size + 1);
}

int main() {
    int a[20], subset[20];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nAll subsets:\n");

    generateSubsets(a, n, 0, subset, 0);

    return 0;
}