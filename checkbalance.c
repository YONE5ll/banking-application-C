#include <stdio.h>

// Define a structure for an account
typedef struct {
   int accountNumber;
   double balance;
} Account;

// Function to check the balance of an account
double checkBalance(Account account) {
   return account.balance;
}

int main() {
   // Example account
   Account myAccount;
   myAccount.accountNumber = 123456;
   myAccount.balance = 1000.50;

   // Check balance
   double balance = checkBalance(myAccount);
   printf("The balance for account number %d is: $%.2f\n", myAccount.accountNumber, balance);

   return 0;
}