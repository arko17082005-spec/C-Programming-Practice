#include <stdio.h>

int main() {
    int a[100], b[100];
    int n, m, i, j, found;

    printf("Enter the size of first array: ");
    scanf("%d", &n);

    printf("Enter first array: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of second array: ");
    scanf("%d", &m);

    printf("Enter first array: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &b[i]);
    }

    printf("Intersection: ");

    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if(a[i] == b[j]) {
                printf("%d", a[i]);
                break;
            }
        }
    }

    printf("\nUnion: ");

    for(i=0;i<n;i++) {
        printf("%d", a[i]);
    }

    for(i=0;i<m;i++) {
        found = 0;

        for(j=0;j<n;j++) {
            if(b[i] == a[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("%d", b[i]);
        }
    }
    
    return 0;
}