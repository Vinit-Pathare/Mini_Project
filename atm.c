#include <stdio.h>

// Function prototypes
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    float balance = 0.0;
    int choice;

    printf("Welcome to the ATM System!\n");

   while (1) 
   {
        // Display menu
        printf("\nChoose an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: %.2f\n", balance);
}

// Function to deposit money
float depositMoney(float balance) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited %.2f. Your new balance is %.2f\n", amount, balance);
    } else {
        printf("Invalid amount. Deposit failed.\n");
    }
    return balance;
}

// Function to withdraw money
float withdrawMoney(float balance) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Successfully withdrew %.2f. Your new balance is %.2f\n", amount, balance);
    } else if (amount > balance) {
        printf("Insufficient balance. Withdrawal failed.\n");
    } else {
        printf("Invalid amount. Withdrawal failed.\n");
    }
    return balance;
}
