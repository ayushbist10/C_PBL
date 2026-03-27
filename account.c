#include <stdio.h>
#include <string.h>
#include "account.h"

#define FILE_NAME "accounts.dat"

void createAccount() {
    struct Account acc;
    FILE *fp = fopen(FILE_NAME, "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Name: ");
    scanf("%s", acc.name);

    printf("Set Password: ");
    scanf("%s", acc.password);

    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account Created Successfully!\n");
}

void viewDetails(int accNo) {
    struct Account acc;
    FILE *fp = fopen(FILE_NAME, "rb");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("\nAccount No: %d\nName: %s\nBalance: %.2f\n",
                   acc.accNo, acc.name, acc.balance);
            break;
        }
    }

    fclose(fp);
}
