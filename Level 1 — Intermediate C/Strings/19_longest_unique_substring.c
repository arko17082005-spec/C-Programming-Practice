#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int lastIndex[256];
    int i, start=0, maxLength=0;
    int maxStart = 0, length;

    printf("Enter a String: ");
    fgets(str, sizeof(str),stdin);

    str[strcspn(str, "\n")] = '\0';

    for (i=0;i<256;i++) {
        lastIndex[i] = -1;
    }

    for (i=0;str[i] != '\0';i++) {
        unsigned char ch = str[i];

        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }

        lastIndex[ch] = i;

        length = i - start + 1;

        if (length > maxLength) {
            maxLength = length;
            maxStart = start;
        }
    }

    printf("Longest substring: ");

    for (i=maxStart;i<maxStart + maxLength; i++) {
        printf("%c", str[i]);
    }

    printf("\nLength: %d\n", maxLength);

    return 0;
}