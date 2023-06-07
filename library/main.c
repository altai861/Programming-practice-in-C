#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "gurvaljin.h"

int main(){
    double gurvaljin[] = {6, 8, 10};
    double gurvaljin2[] = {3, 4, 5};
    if (gurvaljin_tosoo(gurvaljin, gurvaljin2)){
        printf("Tosootei gurvaljin\n");
    } else {
        printf("Tosoogui gurvaljin\n");
    }

    double tal1,tal2,tal3;
	printf("gurvaljingiin 3 talaa oruulna uu\n");
	scanf("%lf %lf %lf",&tal1, &tal2, &tal3);
	double talbai = gurvaljin_talbai(tal1, tal2, tal3);
	printf("%lf %lf %lf taltai gurvaljnii talbai: %lf\n",tal1, tal2, tal3, talbai);

    double radius = gurvaljin_radius(tal1, tal2, tal3);
    printf("%lf %lf %lf taltai gurvaljnii dotor bagtah toirgiin radius: %lf\n", tal1, tal2, tal3 ,radius);

    double ondor = gurvaljin_ondor(tal1, tal2, tal3);


    printf("%lf %lf %lf taltai gurvaljnii ondor ii urt : %lf\n", ondor);
    double ontsog = gurvaljin_2_tal_nuguu_untsug(tal1, tal2, tal3);
    printf("%lf %lf %lf taltai gurvaljnii %lf taliin oodoos harsan ontsog: %lf\n", tal1, tal2, tal3, tal3, ontsog);

    printf("%lf %lf taluudiin goliin ontsog %lf baihad esreg taliin urt ni: %lf", tal1, tal2, ontsog, gurvaljin_3_dahi_tal(tal1, tal2, ontsog));

    return 0;
}