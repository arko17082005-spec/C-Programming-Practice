#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX];
int count = 0;

void addContact() {
    if (count >= MAX) {
        printf("Contact limit reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %49[^\n]", contacts[count].name);

    printf("Enter phone number: ");
    scanf(" %19s", contacts[count].phone);

    printf("Enter email: ");
    scanf(" %49s", contacts[count].email);

    count++;

    printf("Contact added successfully.\n");
}

void displayContacts() {
    int i;

    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n===== Contact List =====\n");

    for (i = 0; i < count; i++) {
        printf("\nContact %d\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
}

void searchContact() {
    char name[50];
    int i, found = 0;

    printf("Enter name to search: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

void updateContact() {
    char name[50];
    int i, found = 0;

    printf("Enter name to update: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {

            printf("Enter new phone number: ");
            scanf(" %19s", contacts[i].phone);

            printf("Enter new email: ");
            scanf(" %49s", contacts[i].email);

            printf("Contact updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

void deleteContact() {
    char name[50];
    int i, j, found = 0;

    printf("Enter name to delete: ");
    scanf(" %49[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {

            for (j = i; j < count - 1; j++)
                contacts[j] = contacts[j + 1];

            count--;
            found = 1;

            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                searchContact();
                break;

            case 3:
                updateContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                displayContacts();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}