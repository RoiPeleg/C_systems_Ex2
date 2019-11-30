#include "myBank.h"
#include <stdio.h>
double acc[rows][SIZE] = {{0.0}};
int nextFree = 0;//next free spot in the array
void newAccount(double amount)
{
    if (amount < 0)
    {
        printf("amount must be positive\n");
        return;
    }

    if (nextFree < SIZE)
    {
        acc[0][nextFree] = 1.0;
        acc[1][nextFree] = amount;
        printf("new account id is: %d\n", 901 + nextFree);
        nextFree++;
    }
    else
    {
        printf("max accounts reached\n");
    }
    
}
void getBalance(int id)
{
    id = id - 901;
    if (id < 0 || id > SIZE)
    {
        printf("invalid id\n");
        return;
    }
    if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        printf("Balance: %.2lf\n", acc[1][id]);
    }
}
void deposit(int id, double amount)
{
    id = id - 901;
    if (id < 0 || id > SIZE)
    {
        printf("invalid id\n");
        return;
    }
    if (amount <= 0)
    {
        printf("amount must be positive\n");
        return;
    }
    if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        acc[1][id] += amount;
        printf("Balance: %.2lf\n", acc[1][id]);
    }
}
void withdraw(int id, double amount)
{
    if (amount <= 0)
    {
        printf("amount must be positive\n");
        return;
    }
    id = id - 901;
    if (id < 0 || id > SIZE)
    {
        printf("invalid id\n");
        return;
    }
    if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        if (acc[1][id] - amount > 0)
        {
            acc[1][id] -= amount;
            printf("Balance: %.2lf\n", acc[1][id]);
        }
        else
            printf("not enough funds \n");
    }
}
void shut(int id)
{
    id = id - 901;
    if (id < 0 || id < SIZE)
    {
        if (acc[0][id] == 0.0)
        {
            printf("account is aleardy closed \n");
            return;
        }
        for (int i = id + 1; i < nextFree; i++)
        {
            acc[1][i] = acc[1][i + 1];
        }
        acc[0][nextFree - 1] = 0.0;
        nextFree--;
    }
    else
    {
        printf("invalid id\n");
    }
}
void addInterest(int prec)
{
    if (prec < 0)
    {
        printf("precentege should be positive\n");
        return;
    }
    double p = 1 + (prec / 100);
    for (int i = 0; i < nextFree; i++)
    {
        if(acc[0][i]==1.0)
        {
        acc[1][i]=acc[1][i]*p;
        }
    }
}
void report()
{
    for (int i = 0; i < nextFree; i++)
    {
        if (acc[0][i] != 0.0)
            printf("Account number %d balance: %.2lf\n", i + 901, acc[1][i]);
    }
}
void closeAll()
{
    for (int i = 0; i < nextFree; i++)
    {
        acc[0][i] = 0.0;
    }
}