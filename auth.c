#include <stdio.h>
#include <string.h>
#include "account.h"
#include "transaction.h"

#define FILE_NAME "accounts.dat"

void login() {
    int accNo, found = 0;
    char password[20];
    struct Account acc;

    FILE *fp = fopen(FILE_NAME, "rb");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter Password: ");
    scanf("%s", password);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo && strcmp(acc.password, password) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        printf("Invalid Login!\n");
        return;
    }

    int choice;
    while (1) {
        printf("\nWelcome %s\n", acc.name);
        printf("1. Deposit\n2. Withdraw\n3. View Details\n4. Transaction History\n5. Logout\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: deposit(accNo); break;
            case 2: withdraw(accNo); break;
            case 3: viewDetails(accNo); break;
            case 4: transactionHistory(accNo); break;
            case 5: return;
        }
    }
}
