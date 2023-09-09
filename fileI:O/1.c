#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char file_name[100];
    char user_input[1000];

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    // Open the file in append mode
    file = fopen(file_name, "a");

    if (file != NULL) {
        printf("Enter text to write to the file: ");
        scanf(" %[^\n]", user_input);

        fprintf(file, "%s\n", user_input);
        printf("Text written to the file successfully!\n");

        fclose(file);
    } else {
        // Create a new file if it doesn't exist
        file = fopen(file_name, "w");

        if (file != NULL) {
            printf("Enter text to write to the file: ");
            scanf(" %[^\n]", user_input);

            fprintf(file, "%s\n", user_input);
            printf("Text written to the file successfully!\n");

            fclose(file);
        } else {
            printf("Unable to create or open the file.\n");
        }
    }

    return 0;
}
