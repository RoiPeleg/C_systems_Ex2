#ifndef MYBANK
#define MYBANK
#define SIZE 50
#define rows 2
extern double acc[rows][SIZE];
void newAccount(double amount);       //opens new account with given amount as first deposit
void getBalance(int id);              //gets id and printd it's balance
void deposit(int id, double amount);  //gets amount to deposit and prints new balance
void withdraw(int id, double amount); //gets amount to withdraw and prints new balance
void shut(int id);                    //closes given account
void addInterest(int prec);           //adds to all accounts interest by given precentage
void report();                        //prints all opened accounts balance
void closeAll();                      //closes all acounts
#endif