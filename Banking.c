#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *acc, int accNumber, char *name, float balance) {
    acc->accNumber = accNumber;
    strcpy(acc->name, name);
    acc->balance = balance;
}

void deposit(struct Account *acc, float amount) {
    acc->balance += amount;
    printf("Deposit successful. Current balance: %.2f\n", acc->balance);
}

void withdraw(struct Account *acc, float amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrawal successful. Current balance: %.2f\n", acc->balance);
    } else {
        printf("Insufficient balance\n");
    }
}

void display(struct Account *acc) {
    printf("Account Number: %d\n", acc->accNumber);
    printf("Account Holder Name: %s\n", acc->name);
    printf("Balance: %.2f\n", acc->balance);
}

int main() {
    struct Account acc1;
    createAccount(&acc1, 1001, "John Doe", 5000.00);

    int choice;
    float amount;

    do {
        printf("\nBanking System Menu\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Account Information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&acc1, amount);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&acc1, amount);
                break;
            case 3:
                display(&acc1);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}