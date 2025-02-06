#include <stdio.h>

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
        printf(" Oppps! Insufficient Balance. Transaction Failed.\n");
        return;
    }
    
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    
    if (pin != sender_pin) {
        printf("Invalid PIN. Transaction Failed, Pleases try again with thr right pin. Thnak You\n");
        return;
    }
    
    sender_balance -= trans_amt;
    printf("Money Transferred Successfully!\n");
    printf("Current balance is : %d\n", sender_balance);
}

int main() {
    printf("WELCOME TO YOUR FINANCE Service Department:\n");
    printf("Please have patience till your transaction is completed. :\n");
    transfer_money();
    printf("Thank you for using our Financial Service Department. Visit Again!\n");
    return 0;
}
 
