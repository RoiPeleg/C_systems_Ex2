#include "myBank.h"
#include <stdio.h>
int main()
{
    char input = 'X';
    double amount = 0.0;
    int id = -1,N=0;
    int intrest = 0;
   do
    {
        input = 'X';
        printf("Transaction type?:");
        N = scanf(" %c", &input);
        if (N != 1)
        {
            printf("invalid in\n");
        }  
        else
        {
            switch (input)
            {
            case 'O':
                printf("Initial deposit?:");
                if (scanf("  %lf", &amount) != 1)
                {
                    printf("invalid input\n");
                    continue;
                }
                   newAccount(amount);
                break;
            case 'B':
                printf("Account number:");
                if (scanf(" %d", &id) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                getBalance(id);
                break;
            case 'D':
                printf("Account number:");
                if (scanf(" %d", &id) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                printf("Amount?:");
                if (scanf(" %lf", &amount) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                deposit(id, amount);
                break;
            case 'W':
                printf("Account number:");
                if (scanf(" %d", &id) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                printf("Amount?:");
                if (scanf(" %lf", &amount) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                withdraw(id, amount);
                break;
            case 'C':
                printf("Account number:");
                if (scanf(" %d", &id) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                shut(id);
                break;
            case 'I':
                printf("Interest rate?:");
                if (scanf(" %d", &intrest) != 1)
                {
                    printf("invalid input\n");
                    break;
                }
                addInterest(intrest);
                break;
            case 'P':
                report();
                break;
            case 'E':
                break;
            default:
                printf("invalid input\n");
            }
        }
    } while (input != 'E');
    return 0;
}