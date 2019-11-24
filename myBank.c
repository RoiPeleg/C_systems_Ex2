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
    id = id -901;
    if(id<0 || id>49)
    {
        printf("invalid id");
        return;
    }
    if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        printf("Balance: %lf\n", acc[1][id]);
    }
}
void deposit(int id, double amount) {
    id = id -901;
    if(id<0 || id>49)
    {
        printf("invalid id");
        return;
    }
     if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        acc[1][id] +=amount;
        printf("Balance: %lf\n", acc[1][id]);
    }
}
void withdraw(int id, double amount) {
    id = id -901;
    if(id<0 || id>49)
    {
        printf("invalid id");
        return;
    }
     if (acc[0][id] == 0.0)
    {
        printf("closed account \n");
    }
    else
    {
        if(acc[1][id]-amount > 0)
        {
            acc[1][id] -=amount;
        printf("Balance: %lf\n", acc[1][id]);
        }
        else printf("not enough funds");
    }
}
void shut(int id) {
    if(id-901 < 49)
    {
       for(int i=id+1;i<nextFree;i++)
       {
       acc[1][i]=acc[1][i+1];
       }
       acc[0][nextFree-1]=0.0;
       nextFree--;
    }
    else
    {
        printf("invalid id\n");
    }
    
}
void addInterest(double prec) {
        for (int i = 0; i < nextFree; i++)
        {
            acc[1][i] = acc[1][i]*(prec) + acc[1][i]*(prec/100);
        }
}
void report()
{
    for (int i = 0; i < nextFree; i++)
    {
        if (acc[0][i]!=0.0) printf("Account number %d balance: %lf\n", i+901, acc[1][i]);
    }
}