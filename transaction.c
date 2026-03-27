#include <stdio.h>
#include <string.h>
#include "account.h"

#define FILE_NAME "accounts.dat"
#define TRANS_FILE "transactions.dat"

void deposit(int accNo) {
    float amt;
    struct Account acc;
    FILE *fp = fopen(FILE_NAME, "rb+");

    printf("Enter amount: ");
    scanf("%f", &amt);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            acc.balance += amt;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            break;
        }
    }
    fclose(fp);

    FILE *tf = fopen(TRANS_FILE, "a");
    fprintf(tf, "AccNo: %d Deposited: %.2f\n", accNo, amt);
    fclose(tf);

    printf("Deposit Successful!\n");
}

void withdraw(int accNo) {
    float amt;
    struct Account acc;
    FILE *fp = fopen(FILE_NAME, "rb+");

    printf("Enter amount: ");
    scanf("%f", &amt);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            if (acc.balance >= amt) {
                acc.balance -= amt;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);

                FILE *tf = fopen(TRANS_FILE, "a");
                fprintf(tf, "AccNo: %d Withdrawn: %.2f\n", accNo, amt);
                fclose(tf);

                printf("Withdrawal Successful!\n");
            } else {
                printf("Insufficient Balance!\n");
            }
            break;
        }
    }
    fclose(fp);
}

void transactionHistory(int accNo) {
    FILE *tf = fopen(TRANS_FILE, "r");
    char line[100];

    printf("\n--- Transaction History ---\n");

    while (fgets(line, sizeof(line), tf)) {
        int id;
        if (sscanf(line, "AccNo: %d", &id) == 1) {
            if (id == accNo) {
                printf("%s", line);
            }
        }
    }

    fclose(tf);
}
