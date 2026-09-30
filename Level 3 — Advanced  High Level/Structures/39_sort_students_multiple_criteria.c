#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100], temp;
    int n, choice, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nSort students by:\n");
    printf("1. Marks\n");
    printf("2. Name\n");
    printf("3. Roll Number\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            int shouldSwap = 0;

            if (choice == 1 &&
                s[j].marks < s[j + 1].marks) {
                shouldSwap = 1;
            }

            else if (choice == 2 &&
                     strcmp(s[j].name,
                            s[j + 1].name) > 0) {
                shouldSwap = 1;
            }

            else if (choice == 3 &&
                     s[j].roll > s[j + 1].roll) {
                shouldSwap = 1;
            }

            if (shouldSwap) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n===== Sorted Students =====\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }

    return 0;
}