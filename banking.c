#include <stdio.h>
char name[20];
int dpt_amount, amount = 10000, acc_no, choice;

void menu();
void check_balance();
void deposite_money();
void withdraw_money();
void transfer_money();

int main()
{

    printf("enter you name");
    gets(name);
    printf("enter your account number");
    scanf("%d", &acc_no);

    menu();
    printf("enter your choice");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        deposite_money();
        break;

    case 2:
        withdraw_money();
        break;

    case 3:
        transfer_money();
        break;

        //  check_balance();
        // //     break;

    default:
        printf("invalid choice");
        break;
    }

    return 0;
}

void menu()
{
    printf("1. deposit\n");
    printf("2. withdraw\n");
    printf("3.transfer balance\n");
    printf("4. check balance\n");
    printf("5. exit\n");
}
void deposite_money()
{
    printf("enter the amount you want to deposite");
    scanf("%d", &dpt_amount);
    amount += dpt_amount;
    printf("your balance is %d", amount);
}
// subha ko part
void withdraw_money()
{
    float balance = 1000.00;
    float withdrawAmount;
    char choice;
    int blocked = 0;

    printf("Welcome to the Bank!\n");
    printf("Your current balance is: %.2f\n", balance);

    do
    {
        if (blocked)
        {
            printf("Your account is temporarily blocked due to suspension.\n");
            break;
        }

        printf("Enter the amount to withdraw: ");
        scanf("%f", &withdrawAmount);

        if (withdrawAmount > balance)
        {
            printf("Insufficient funds! Your balance is %.2f\n", balance);
        }
        else if (withdrawAmount <= 0)
        {
            printf("Invalid amount! Please enter a positive number.\n");
        }
        else if (withdrawAmount >= balance * 0.8)
        {
            blocked = 1;
            printf("Security alert!.\n");
            printf("Your account has been temporarily blocked due to suspension. Please contact customer service.\n");
        }
        else
        {
            balance -= withdrawAmount;
            printf("Withdrawal successful! Your new balance is %.2f\n", balance);
        }

        if (!blocked)
        {
            printf("Do you want another transaction? (y/n): ");
            scanf(" %c", &choice);
        }
        else
        {
            choice = 'n';
        }

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using our bank!\n");
}

// nirjala and suman ko part
void transfer_money()
{
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

    if (trans_amt > sender_balance)
    {
        printf(" Oppps! Insufficient Balance. Transaction Failed.\n");
        return;
    }

    printf("Enter your PIN: ");
    scanf("%d", &pin);
    if (pin != sender_pin)
    {
        printf("Invalid PIN. Transaction Failed, Pleases try again with thr right pin. Thnak You\n");
        return;
    }

    sender_balance -= trans_amt;
    printf("Money Transferred Successfully!\n");
    printf("Current balance is : %d\n", sender_balance);
}