#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int modeChoice;

    do {
        printf("Main Menu:\n");
        printf("1. Admin Mode\n");
        printf("2. User Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &modeChoice);

        switch (modeChoice) {
            case 1:
                // Run the admin program as a separate process
                system("admin.exe"); // Replace with the actual executable name
                break;
            case 2:
                // Run the user program as a separate process
                system("user.exe"); // Replace with the actual executable name
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (modeChoice != 3);

    return 0;
}
