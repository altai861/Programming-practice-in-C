#include <gurvaljin.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    double massive[3] = {1, 2, 3};
    if (gurvaljin_mun_by_massive(massive)) {
        printf("Gurvaljin mon");
    } else {
        printf("gurvaljin bish");
    }

    //gcc -o my_program 1.c -lgurvaljin -I/usr/local/include -L/usr/local/lib


}