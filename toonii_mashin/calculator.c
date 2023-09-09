#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double a) {
    return sqrt(a);
}

int main() {
    int choice;
    double num1, num2, result;
    int exit = 0;
    int firstNumberSet = 0;

    while (!exit) {
        system("clear"); // Clear the screen

        printf("1. Nemeh\n");
        printf("2. Hasah\n");
        printf("3. Urjih\n");
        printf("4. Huvaah\n");
        printf("5. Zeregt devshuuleh\n");
        printf("6. Yazguur avah\n");
        printf("7. Garah\n");
        printf("Songoltoo oruulna uu ! (1-7): ");
        scanf("%d", &choice);

        if (firstNumberSet) {
            printf("Umnuh hariu : %.2f\n", result);
        }

        switch (choice) {
            case 1:
                if (firstNumberSet) {
                    printf("2 too oruulna uu : ");
                    scanf("%lf", &num2);
                    result = add(result, num2);
                } else {
                    printf("2 too oruulna uu : ");
                    scanf("%lf %lf", &num1, &num2);
                    result = add(num1, num2);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 2:
                if (firstNumberSet) {
                    printf("2 too oruulna uu: ");
                    scanf("%lf", &num2);
                    result = subtract(result, num2);
                } else {
                    printf("2 too oruulna uu: ");
                    scanf("%lf %lf", &num1, &num2);
                    result = subtract(num1, num2);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 3:
                if (firstNumberSet) {
                    printf("2 too oruulna uu: ");
                    scanf("%lf", &num2);
                    result = multiply(result, num2);
                } else {
                    printf("2 too oruulna uu: ");
                    scanf("%lf %lf", &num1, &num2);
                    result = multiply(num1, num2);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 4:
                if (firstNumberSet) {
                    printf("2 too oruulna uu: ");
                    scanf("%lf", &num2);
                    result = divide(result, num2);
                } else {
                    printf("2 too oruulna uu: ");
                    scanf("%lf %lf", &num1, &num2);
                    result = divide(num1, num2);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 5:
                if (firstNumberSet) {
                    printf("2 too oruulna uu: ");
                    scanf("%lf", &num2);
                    result = power(result, num2);
                } else {
                    printf("2 too oruulna uu: ");
                    scanf("%lf %lf", &num1, &num2);
                    result = power(num1, num2);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 6:
                if (firstNumberSet) {
                    result = squareRoot(result);
                } else {
                    printf("1 too oruulna uu : ");
                    scanf("%lf", &num1);
                    result = squareRoot(num1);
                    firstNumberSet = 1;
                }
                printf("Hariu : %.2f\n", result);
                break;
            case 7:
                exit = 1;
                break;
            default:
                printf("Buruu utga ! \n");
                break;
        }

        if (!exit) {
            getchar();
            printf("Enter tovchiig darna uu ...");
            getchar(); 
        }
    }

    return 0;
}

