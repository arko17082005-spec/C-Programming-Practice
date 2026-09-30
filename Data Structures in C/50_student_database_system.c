#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Database {
    struct Student *students;
    int count;
    int capacity;
};

/* Initialize database */
void initialize(struct Database *db) {
    db->count = 0;
    db->capacity = 5;

    db->students = (struct Student *)
                   malloc(db->capacity *
                          sizeof(struct Student));

    if (db->students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

/* Resize dynamic array */
void resize(struct Database *db) {
    struct Student *temp;

    db->capacity *= 2;

    temp = (struct Student *)
           realloc(db->students,
                   db->capacity *
                   sizeof(struct Student));

    if (temp == NULL) {
        printf("Memory reallocation failed.\n");
        free(db->students);
        exit(1);
    }

    db->students = temp;
}

/* Find student by roll number */
int findStudent(struct Database *db, int roll) {
    int i;

    for (i = 0; i < db->count; i++) {
        if (db->students[i].roll == roll)
            return i;
    }

    return -1;
}

/* Add student */
void addStudent(struct Database *db) {
    struct Student *s;

    if (db->count == db->capacity)
        resize(db);

    s = &db->students[db->count];

    printf("Enter roll number: ");
    scanf("%d", &s->roll);

    if (findStudent(db, s->roll) != -1) {
        printf("Roll number already exists.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %49[^\n]", s->name);

    printf("Enter marks: ");
    scanf("%f", &s->marks);

    db->count++;

    printf("Student added successfully.\n");
}

/* Delete student */
void deleteStudent(struct Database *db) {
    int roll, index, i;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    index = findStudent(db, roll);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (i = index; i < db->count - 1; i++)
        db->students[i] = db->students[i + 1];

    db->count--;

    printf("Student deleted successfully.\n");
}

/* Update student */
void updateStudent(struct Database *db) {
    int roll, index;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    index = findStudent(db, roll);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %49[^\n]", db->students[index].name);

    printf("Enter new marks: ");
    scanf("%f", &db->students[index].marks);

    printf("Student updated successfully.\n");
}

/* Search student */
void searchStudent(struct Database *db) {
    int roll, index;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    index = findStudent(db, roll);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nStudent Found\n");
    printf("Roll: %d\n", db->students[index].roll);
    printf("Name: %s\n", db->students[index].name);
    printf("Marks: %.2f\n", db->students[index].marks);
}

/* Sort by marks */
void sortStudents(struct Database *db) {
    int choice, i, j;
    struct Student temp;

    printf("\nSort by:\n");
    printf("1. Marks\n");
    printf("2. Name\n");
    printf("3. Roll Number\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < db->count - 1; i++) {
        for (j = 0; j < db->count - i - 1; j++) {

            int swap = 0;

            if (choice == 1 &&
                db->students[j].marks <
                db->students[j + 1].marks) {
                swap = 1;
            }

            else if (choice == 2 &&
                     strcmp(db->students[j].name,
                            db->students[j + 1].name) > 0) {
                swap = 1;
            }

            else if (choice == 3 &&
                     db->students[j].roll >
                     db->students[j + 1].roll) {
                swap = 1;
            }

            if (swap) {
                temp = db->students[j];
                db->students[j] =
                    db->students[j + 1];
                db->students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted successfully.\n");
}

/* Display all students */
void displayStudents(struct Database *db) {
    int i;

    if (db->count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n===== All Students =====\n");

    for (i = 0; i < db->count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll: %d\n", db->students[i].roll);
        printf("Name: %s\n", db->students[i].name);
        printf("Marks: %.2f\n", db->students[i].marks);
    }
}

/* Save students to file */
void saveToFile(struct Database *db) {
    FILE *file;

    file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    fwrite(&db->count, sizeof(int), 1, file);

    fwrite(db->students,
           sizeof(struct Student),
           db->count,
           file);

    fclose(file);

    printf("Data saved successfully.\n");
}

/* Load students from file */
void loadFromFile(struct Database *db) {
    FILE *file;
    int count;

    file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("No saved data found.\n");
        return;
    }

    fread(&count, sizeof(int), 1, file);

    while (db->capacity < count)
        resize(db);

    fread(db->students,
          sizeof(struct Student),
          count,
          file);

    db->count = count;

    fclose(file);

    printf("%d student records loaded.\n", count);
}

/* Free memory */
void cleanup(struct Database *db) {
    free(db->students);
    db->students = NULL;
    db->count = 0;
    db->capacity = 0;
}

int main() {
    struct Database db;
    int choice;

    initialize(&db);

    do {
        printf("\n================================\n");
        printf("     STUDENT DATABASE SYSTEM\n");
        printf("================================\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Sort Students\n");
        printf("6. Display All Students\n");
        printf("7. Save to File\n");
        printf("8. Load from File\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(&db);
                break;

            case 2:
                deleteStudent(&db);
                break;

            case 3:
                updateStudent(&db);
                break;

            case 4:
                searchStudent(&db);
                break;

            case 5:
                sortStudents(&db);
                break;

            case 6:
                displayStudents(&db);
                break;

            case 7:
                saveToFile(&db);
                break;

            case 8:
                loadFromFile(&db);
                break;

            case 9:
                cleanup(&db);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}