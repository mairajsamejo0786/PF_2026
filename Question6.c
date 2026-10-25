#include <stdio.h>

int deposit(float *balance, float amount)
{
    if (amount <= 0)
    {
        return 0;
    }
    *balance = *balance + amount;
    return 1;
}

int withdraw(float *balance, float amount)
{
    if (amount <= 0 || amount > *balance)
    {
        return 0;
    }
    *balance = *balance - amount;
    return 1;
}

int main()
{
    float balance = 1000;
    float amount;
    int choice;

    while (1)
    {
        printf("\n1 Deposit\n2 Withdraw\n3 Check balance\n4 Exit\n");
        printf("Choose option (1-4): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (deposit(&balance, amount) == 1)
            {
                printf("Amount deposited successfully.\n");
            }
            else
            {
                printf("Invalid amount.\n");
            }
        }
        else if (choice == 2)
        {
            printf("Enter amount: ");
            scanf("%f", &amount);
            if (withdraw(&balance, amount) == 1)
            {
                printf("Amount withdrawn successfully.\n");
            }
            else
            {
                printf("Insufficient funds or invalid amount.\n");
            }
        }
        else if (choice == 3)
        {
            printf("Current balance: %.2f\n", balance);
        }
        else if (choice == 4)
        {
            printf("Goodbye.\n");
            break;
        }
        else
        {
            printf("Invalid option\n");
        }
    }

    return 0;
}