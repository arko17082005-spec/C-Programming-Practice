#include <stdio.h>

int my_strlen(const char *str) {
    const char *p = str;
    while (*p) {
        p++;
    }
    return p - str;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d\n", my_strlen(str));

    return 0;
}