#include <stdio.h>

#define MAX 100

struct Account {
    int accountNo;
    char name[50];
    float balance;
};

struct Account accounts[MAX];
int count = 0;

void createAccount() {
    if (count >= MAX) {
        printf("Account limit reached.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[count].accountNo);

    printf("Enter account holder name: ");
    scanf(" %49[^\n]", accounts[count].name);

    printf("Enter initial balance: ");
    scanf("%f", &accounts[count].balance);

    count++;

    printf("Account created successfully.\n");
}

int findAccount(int accountNo) {
    int i;

    for (i = 0; i < count; i++) {
        if (accounts[i].accountNo == accountNo)
            return i;
    }

    return -1;
}

void deposit() {
    int accountNo, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = findAccount(accountNo);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[index].balance += amount;

    printf("Deposit successful.\n");
    printf("New balance: %.2f\n", accounts[index].balance);
}

void withdraw() {
    int accountNo, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = findAccount(accountNo);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;

    printf("Withdrawal successful.\n");
    printf("Remaining balance: %.2f\n",
           accounts[index].balance);
}

void searchAccount() {
    int accountNo, index;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = findAccount(accountNo);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("\nAccount Found!\n");
    printf("Account Number: %d\n",
           accounts[index].accountNo);
    printf("Name: %s\n", accounts[index].name);
    printf("Balance: %.2f\n",
           accounts[index].balance);
}

void displayBalance() {
    int accountNo, index;

    printf("Enter account number: ");
    scanf("%d", &accountNo);

    index = findAccount(accountNo);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Account Holder: %s\n",
           accounts[index].name);
    printf("Balance: %.2f\n",
           accounts[index].balance);
}

int main() {
    int choice;

    do {
        printf("\n===== Bank Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Search Account\n");
        printf("5. Display Balance\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                searchAccount();
                break;

            case 5:
                displayBalance();
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