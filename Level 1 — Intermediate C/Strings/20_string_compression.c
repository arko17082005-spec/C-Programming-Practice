#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0, count;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Compressed string: ");

    while (str[i] != '\0') {
        count = 1;

        while (str[i] == str[i + 1] && str[i] != '\0') {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
        i++;
    }

    printf("\n");

    return 0;
}