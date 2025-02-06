// this is the branch to check balance
#include <stdio.h>
#include <string.h>

void banking_login()
{
    FILE *fp;
    char username[50];
    fp = fopen("banking.txt", "r");
    if (fp == NULL)
    {
        printf("error opening \n try again");
    }

    printf("enter the username ");
    scanf("%s", &username);

    checkbalance(fp, username);

    fclose(fp);
}

void checkbalance(FILE *fp, const char *username)
{
    char storeduser_name[50];
    float balance;

    rewind(fp);
    while (fscanf(fp, "%s%f", storeduser_name, &balance) != EOF)
    {
        if (strcmp(storeduser_name, username) == 0)
        {
            printf("your balance in this account is %.2f", balance);
            return;
        }
    }
    printf("user not found");
}