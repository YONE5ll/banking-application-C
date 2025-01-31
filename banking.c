#include<stdio.h>
char name[20];
    int dpt_amount,amount=10000,acc_no,choice;

void menu();
void check_balance();
void deposite_money();
// void withdraw_money();
// void transfer_money();

int main(){
    

    printf("enter you name");
    gets(name);
    printf("enter your account number");
    scanf("%d",&acc_no);

    menu();
    printf("enter your choice");
    scanf("%d",&choice);
     
     switch (choice)
     {
     case 1:
     deposite_money();
        break;
     case 2:
     check_balance();
    //     break;
    //  case 3:
    //  transfer_money();
    //     break;
     
     default:
        printf("invalid choice");
        break;
     }
    return 0;
}
void menu(){
     printf("1. deposit\n");
    printf("2. check balance\n");
    printf("3. withdraw\n");
    printf("4. exit\n");
}
void deposite_money(){
    printf("enter the amount you want to deposite");
    scanf("%d",&dpt_amount);
    amount+=dpt_amount;
    printf("your balance is %d",amount);
}