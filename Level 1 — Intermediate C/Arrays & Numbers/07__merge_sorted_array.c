#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n, m, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &n);
    
    printf("Enter first sorted array: \n");
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    printf("Enter size of sorted array: ");
    scanf("%d", &m);

    printf("Enter second sorted array: \n");
    for(i=0;i<m;i++){
        scanf("%d", &b[i]);
    }
    i=0;
    j=0;
    k=0;

    while (i<n && j<m) {
        if(a[i]<b[j]){
            c[k++] = a[i++];
        }else{
            c[k++] = b[j++];
        }
    }
    while (i<n) {
        c[k++] = b[j++];
    }
    while (j<m) {
        c[k++] = b[j++];
    }
    
    printf("Merged sortred array: \n");
    for(i=0;i<k;i++){
        printf("%d", c[i]);
    }
    return 0;
}