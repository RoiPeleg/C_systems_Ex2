#include "myBank.h"
#include <stdio.h>
int main()
{
    char input = 'X';
    double amount = 0.0;
    int id = -1;
    while (input != 'E')
    {
        switch (input)
        {
        case 'X':
        break;
        case 'O':
            printf("Initial deposit?:");
            scanf(" %lf", &amount);
            newAccount(amount);
            break;
        case 'B':
            printf("Account number:");
            scanf(" %d", &id);
            getBalance(id);
            break;
        case 'D':
            printf("Account number:");
            scanf(" %d", &id);
            printf("Amount?:");
            scanf(" %lf", &amount);
            deposit(id, amount);
            break;
        case 'W':
            printf("Account number:");
            scanf(" %d", &id);
            printf("Amount?:");
            scanf(" %lf", &amount);
            withdraw(id, amount);
            break;
        case 'C':
            printf("Account number:");
            scanf(" %d", &id);
            shut(id);
            break;
        case 'I':
            printf("Interest rate?:");
            scanf(" %lf", &amount);
            addInterest(amount);
            break;
        case 'P':
            report();
            break;
        default:
        printf("invalid input\n");
        break;
        }
        printf("Transaction type?:");
        scanf(" %c", &input);
    }
    return 0;
}