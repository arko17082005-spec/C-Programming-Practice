#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char word[100], longest[100];
    int i = 0, j, maxLength = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    while (str[i] != '\0') {
        while (str[i] == ' '){
            i++;
        }
        j = 0;
    
        while (str[i] != '\0' && str[i] != ' ') {
            word[j++] = str[i++];
        }

        word[j] = '\0';
        
        if (j > maxLength) {
            maxLength = j;
            strcpy(longest, word);
        }
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLength);

    return 0;
}