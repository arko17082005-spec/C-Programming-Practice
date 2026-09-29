#include <stdio.h>

int main() {
    int a[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    for(i=0;i<n;i++) {
        if(i%2 == 0 && a[i] < 0) {
            for(j=i+1;j<n;j++) {
                if(a[j] >= 0) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }

        if (i%2 == 1 && a[i] >= 0) {
            for (j=i+1;j<n;j++) {
                if(a[j] < 0) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }
    }

    printf("Rearranged array: \n");
    for (i=0;i<n;i++) {
        printf("%d", a[i]);
    }

    return 0;
}