#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account {
    int accNo;
    char name[50];
    char password[20];
    float balance;
};

void createAccount();
void viewDetails(int accNo);

#endif
