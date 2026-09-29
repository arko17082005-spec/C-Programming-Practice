#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int visited[256] = {0};
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (!visited[ch]) {
            visited[ch] = 1;
            str[j++] = str[i];
        }
    }

    str[j] = '\0';

    printf("String after removing duplicates: %s\n", str);

    return 0;
}