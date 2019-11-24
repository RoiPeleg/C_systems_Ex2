#include "myBank.h"
#include <stdio.h>

double acc[1][49];
int nextFree = 0;
void init()
{
    for (int i = 0; i < nextFree; i++)
    {
        acc[0][i] = 0.0;
        acc[1][i] = 0.0;
    }
}
void newAccount(double amount)
{
    if (nextFree < 49)
    {
        acc[0][nextFree] = 1;
        acc[1][nextFree] = amount;
        nextFree++;
    }
}
void getBalance(int id)
{
    if (acc[0][id] == 0.0)
    {
        printf("closed account /n");
    }
    else
    {
        printf("Balance: %lf", acc[1][id]);
    }
}
void deposit(int id, double amount) { ; }
void withdraw(int id, double amount) { ; }
void shut(int id) { ; }
void addInterest(double prec) { ; }
void report()
{
    for (int i = 0; i < nextFree; i++)
    {
        printf("val acc[1][%d] = %lf", i, acc[1][i]);
        printf("\n");
    }
}