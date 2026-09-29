#include <stdio.h>
int main() {
    int a[100], n, k, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter K: ");
    scanf("%d", &k);
    k-k%n;
    for(i=0;i<k;i++) {
        temp = a[0];
        for(j=0;j<n-1;j++){
            a[j]=a[j+1];
        }
        a[n-1]=temp;
    }
    printf("After left rotaion: \n");
    for(i=0;i<n;i++){
        printf("%d", a[i]);
    }
    return 0;
}