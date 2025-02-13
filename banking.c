#include <stdio.h>
#include <string.h>

char name[20];
int acc_no, choice;

void menu();
void check_balance();
void deposit_money();
void withdraw_money();
void transfer_money();
void initialize_account();

int main() {
    printf("Enter your name: ");
    gets(name);
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    initialize_account();
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit_money();
                break;
            case 2:
                withdraw_money();
                break;
            case 3:
                transfer_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void menu() {
    printf("\n1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Transfer balance\n");
    printf("4. Check balance\n");
    printf("5. Exit\n");
}

void initialize_account() {
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        fp = fopen("account.txt", "w");
        if (fp != NULL) {
            fprintf(fp, "%d %.2lf", acc_no, 10000.00);
            fclose(fp);
        }
    } else {
        fclose(fp);
    }
}

void deposit_money() {
    FILE *fp = fopen("account.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int acc;
    double balance, amount;
    fscanf(fp, "%d %lf", &acc, &balance);

    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    balance += amount;
    rewind(fp);
    fprintf(fp, "%d %.2lf", acc, balance);
    fclose(fp);

    printf("Your new balance is %.2lf\n", balance);
}

void withdraw_money() {
    FILE *fp = fopen("account.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int acc;
    double balance, amount;
    fscanf(fp, "%d %lf", &acc, &balance);

    printf("Your balance is: %.2lf\n", balance);
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > balance) {
        printf("Insufficient funds!\n");
    } else {
        balance -= amount;
        rewind(fp);
        fprintf(fp, "%d %.2lf", acc, balance);
        printf("Withdrawal successful! Your new balance is %.2lf\n", balance);
    }
    fclose(fp);
}

void transfer_money() {
    FILE *fp = fopen("account.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int acc;
    double balance, amount;
    int receiver_acc, pin, correct_pin = 5566;
    
    fscanf(fp, "%d %lf", &acc, &balance);

    printf("Enter receiver account number: ");
    scanf("%d", &receiver_acc);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);

    if (amount > balance) {
        printf("Insufficient Balance. Transaction Failed.\n");
        fclose(fp);
        return;
    }

    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (pin != correct_pin) {
        printf("Invalid PIN. Transaction Failed.\n");
        fclose(fp);
        return;
    }

    balance -= amount;
    rewind(fp);
    fprintf(fp, "%d %.2lf", acc, balance);
    fclose(fp);

    printf("Money Transferred Successfully! Your new balance is %.2lf\n", balance);
}

void check_balance() {
    FILE *fp = fopen("account.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int acc;
    double balance;
    fscanf(fp, "%d %lf", &acc, &balance);
    printf("The balance for account number %d is: $%.2lf\n", acc, balance);
    fclose(fp);
}
