#include <stdio.h>

int is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

int is_alpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
    char str[1000];
    FILE *file;
    int ch;
    int utga;

    printf("Ta hussen text ee oruulj blno\n");
    file = fopen("output.txt", "w");
    printf("Text oruulna uu: ");
    fgets(str, sizeof(str), stdin);

    fprintf(file, "%s", str);

    fclose(file);

    do {
        printf("\n1.Ta textees toog n ylghiig huswel-1\n");
        printf("2.Ta textees usegiig n ylghiig huswel-2\n");
        printf("Exit hiih bol 0 oruulna uu: ");

        scanf("%d", &utga);

        switch (utga) {
            case 1:
                file = fopen("output.txt", "r");
                printf("File dotorh toonuud:\n");

                while ((ch = fgetc(file)) != EOF) {
                    if (is_digit(ch)) {
                        printf("%c ", ch);
                    }
                }

                fclose(file);
                break;
            case 2:
                file = fopen("output.txt", "r");
                printf("File dotorh ugnuud:\n");

                while ((ch = fgetc(file)) != EOF) {
                    if (is_alpha(ch)) {
                        printf("%c", ch);
                    } else if (ch == ' ') {
                        printf(" ");
                    }
                }

                fclose(file);
                break;
            case 0:
                printf("Programaas garlaa.\n");
                break;
            default:
                printf("Buruu vildel oruulaa. Daraagiin vildel oruulna uu.\n");
                break;
        }
    } while (utga != 0);

    return 0;
}

