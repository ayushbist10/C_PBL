#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "auth.h"

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
