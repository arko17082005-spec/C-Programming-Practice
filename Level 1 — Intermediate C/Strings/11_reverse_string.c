#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);

    printf("Reverse string: ");

    for (i=length-1;i>=0;i--) {
        printf("%c", str[i]);
    }

    return 0;
}
