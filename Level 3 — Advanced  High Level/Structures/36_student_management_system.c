#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);

    printf("Enter name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("Student added successfully.\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int roll, i, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void updateStudent() {
    int roll, i, found = 0;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new name: ");
            scanf(" %49[^\n]", students[i].name);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("Student updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

void deleteStudent() {
    int roll, i, j, found = 0;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (j = i; j < count - 1; j++)
                students[j] = students[j + 1];

            count--;
            found = 1;

            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                deleteStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                displayStudents();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}