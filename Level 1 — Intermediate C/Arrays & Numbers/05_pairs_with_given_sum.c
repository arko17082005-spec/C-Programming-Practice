#include <stdio.h>

int main() {
    int a[100], n, target, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for(i=0;i<n;i++){
        scanf("%d", &target);
    }
    printf("Enter target sum: \n");
    scanf("%d", &target);

    printf("Paris are: \n");

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if (a[i]+a[j]==target) {
                printf("(%d, %d)\n", a[i], a[j]);
            }
        }
    }
    return 0;
}