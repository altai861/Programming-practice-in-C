#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


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
    double num1, num2, result;
    int songolt;

    while (true) { 

        printf("1. Nemeh\n");
        printf("2. Hasah\n");
        printf("3. Urjih\n");
        printf("4. Huvaah\n");
        printf("5. Zeregt devshuuleh\n");
        printf("6. Yazguur avah\n");
        printf("7. Garah\n");
        printf("Songoltoo oruulna uu (1-7): ");
        scanf("%d", &songolt);

        if (songolt == 1) {
            printf("Hed deer hediig nemeh ve: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Hariu: %f \n", add(num1, num2));
        } else if (songolt == 2) {
            printf("Hedees hediig hasah ve: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Hariu: %f \n", subtract(num1, num2));
        } else if (songolt == 3) {
            printf("Hedeeg hedeer urjeh ve: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Hariu: %f \n", multiply(num1, num2));
        } else if (songolt == 4) {
            printf("Hediig heded huvaah ve: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Hariu: %f \n", divide(num1, num2));
        } else if (songolt == 5) {
            printf("Hediig heden zeregt devshuuleh ve: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Hariu: %f \n", subtract(num1, num2));
        } else if (songolt == 6) {
            printf("Yzguur avah too: ");
            scanf("%lf", &num1);
            printf("Hariu: %f \n", squareRoot(num1));
        } else if (songolt == 7) {
            break;
        } else {
            printf("Buruu utga oruulsan baina");
        }

        
    }

    return 0;
}

