#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);

    for (i=0;i<length/2;i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf("Palindrome\n");
    }else {
        printf("Not a Palindrome");
    }

    return 0;
}