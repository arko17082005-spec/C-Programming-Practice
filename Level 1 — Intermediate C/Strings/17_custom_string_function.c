#include <stdio.h>

int my_strlen(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

void my_strcpy(char dest[], char src[]) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int my_strcmp(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

void my_strcat(char dest[], char src[]) {
    int i = 0, j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (dest[i] != '\0') {
        dest[i++] = src[j++];
    }

    dest[i] = '\0';
}

int main() {
    char str1[200] = "Hello ";
    char str2[] = "World";
    char copy[100];

    printf("Lemgth of str1: %d\n", my_strlen(str1));

    my_strcpy(copy, str2);
    printf("Copied string: %s\n", copy);

    printf("Comparison result: %d\n", my_strcmp(str1, str2));
    my_strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}