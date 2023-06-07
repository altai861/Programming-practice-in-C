#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//void randoomoor_utga_olgoh()
void random_utga(int massive[], int urt){
    for (int i = 0; i < urt; i++){
        massive[i] = rand() % 100;
    }
}

void garaas(int massive[], int urt){
    for (int i = 0; i < urt; i++){
        printf("%i dahi elementiig oruulna uu: ", i + 1);
        scanf("%i", &massive[i]);
    }
}

int maxx(int massive[], int urt){
    int max = INT16_MIN;
    for (int i = 0; i < urt; i++){
        if (massive[i] > max){
            max = massive[i];
        }
    }
    return max;
}

int minn(int massive[], int urt){
    int min = INT16_MAX;
    for (int i = 0; i < urt; i++){
        if (massive[i] < min){
            min = massive[i];
        }
    }
    return min;
}

float avgg(int massive[], int urt){
    int sum = 0;
    for (int i = 0; i < urt; i++){
        sum = sum + massive[i];
    }

    return (float)sum / (float)urt;

}

void print(int massive[], int urt){
    for (int i = 0; i < urt; i++){
        printf("%i ", massive[i]);
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int massive[], int urt, int s){
    if (s == 1) {
        bool swapped;
        for (int i = 0; i < urt - 1; i++){
            swapped = false;
            for (int j = 0; j < urt - i - 1; j++){
                if (massive[j] < massive[j + 1]){
                    swap(&massive[j], &massive[j+1]);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
    } else if (s == 2) {
        bool swapped;
        for (int i = 0; i < urt - 1; i++){
            swapped = false;
            for (int j = 0; j < urt - i - 1; j++){
                if (massive[j] > massive[j + 1]){
                    swap(&massive[j], &massive[j+1]);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }
}


int main(){

    // massive iin hemjeeg garaas utga avch baina. 
    int urt;
    printf("1 hemjeest massive iin urtiig oruulna uu: ");
    scanf("%i", &urt);
    
    // 1 hemjeest massive iig uusgej baina.
    int massive[urt];

    int songolt;
    printf("Songoltoo oruulna uu: (1: garaas utga oruulna 2: random oor utga oruulna):  ");
    scanf("%i", &songolt);

    if (songolt == 1){
        garaas(massive, urt);
    } else if (songolt == 2){
        random_utga(massive, urt);
    } else {
        printf("Buruu songolt oruulsan baina.");
    }

    // massive hevleh.
    print(massive, urt);
    int s;  
    while (true){
        printf("1. hamgiin ih element\n");
        printf("2. hamgiin baga element\n");
        printf("3. dundaj\n");
        printf("4. Ihees baga ruu erembeleh\n");
        printf("5. Bagaas ih ruu hevleh\n");
        printf("6. Duusgah\n");
        scanf("%i", &s);
        printf("\n");
        switch(s)
        {
            case 1:
                printf("massive iin hamgiin ih element: %i\n", maxx(massive, urt));
            case 2:
                printf("massive iin hamgiin baga element: %i\n", minn(massive, urt));
            case 3:
                printf("massive iin dundaj: %f\n", avgg(massive, urt));
            case 4:
                sort(massive, urt, 1);
                print(massive, urt);
                printf("\n");
            case 5:
                sort(massive, urt, 2);
                print(massive, urt);
                printf("\n");
            case 6:
                break;
        }
        if (s == 6){
            break;
        }
    }
    return 0;
}