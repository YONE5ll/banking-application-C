#include <stdio.h>
#include <string.h>

char name[20];
int dpt_amount, amount = 10000, acc_no, choice;

void menu();
void check_balance();
void deposite_money();
void withdraw_money();
void transfer_money();

typedef struct {
    int accountNumber;
    double balance;
} Account;

// Function to check the balance of an account
double check_Balance(Account account) {
    return account.balance;
}

int main() {
    printf("Enter your name: ");
    gets(name);
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposite_money();
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
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Transfer balance\n");
    printf("4. Check balance\n");
    printf("5. Exit\n");
}

void deposite_money() {
    printf("Enter the amount you want to deposit: ");
    scanf("%d", &dpt_amount);
    amount += dpt_amount;
    printf("Your balance is %d\n", amount);
}

void withdraw_money() {
    float balance = 1000.00;
    float withdrawAmount;
    char choice;
    int blocked = 0;

    printf("Welcome to the Bank!\n");
    printf("Your current balance is: %.2f\n", balance);

    do {
        if (blocked) {
            printf("Your account is temporarily blocked due to suspension.\n");
            break;
        }

        printf("Enter the amount to withdraw: ");
        scanf("%f", &withdrawAmount);

        if (withdrawAmount > balance) {
            printf("Insufficient funds! Your balance is %.2f\n", balance);
        } else if (withdrawAmount <= 0) {
            printf("Invalid amount! Please enter a positive number.\n");
        } else if (withdrawAmount >= balance * 0.8) {
            blocked = 1;
            printf("Security alert!.\n");
            printf("Your account has been temporarily blocked due to suspension. Please contact customer service.\n");
        } else {
            balance -= withdrawAmount;
            printf("Withdrawal successful! Your new balance is %.2f\n", balance);
        }

        if (!blocked) {
            printf("Do you want another transaction? (y/n): ");
            scanf(" %c", &choice);
        } else {
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using our bank!\n");
}

void transfer_money() {
    int sender_ac;
    int receiver_ac;
    int trans_amt;
    int pin;
    int sender_pin = 5566;
    int sender_balance = 100000;

    printf("Enter sender account number: ");
    scanf("%d", &sender_ac);

    printf("Enter receiver account number: ");
    scanf("%d", &receiver_ac);

    printf("Enter the amount to transfer: ");
    scanf("%d", &trans_amt);

    if (trans_amt > sender_balance) {
        printf("Oppps! Insufficient Balance. Transaction Failed.\n");
        return;
    }

    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (pin != sender_pin) {
        printf("Invalid PIN. Transaction Failed, Please try again with the right pin. Thank You\n");
        return;
    }

    sender_balance -= trans_amt;
    printf("Money Transferred Successfully!\n");
    printf("Current balance is : %d\n", sender_balance);
}

void check_balance() {
    Account myAccount;
    myAccount.accountNumber = acc_no;
    myAccount.balance = amount;

    double balance = check_Balance(myAccount);
    printf("The balance for account number %d is: $%.2f\n", myAccount.accountNumber, balance);
}