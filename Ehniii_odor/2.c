#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

//void randoomoor_utga_olgoh()
void random_utga(int row, int column, int massive[row][column]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            massive[i][j] = rand() % 100;
        }
        
    }
}

void garaas(int row, int column, int massive[row][column]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%i mornii %i bagana dahi elementiig oruulna uu: ", i + 1, j + 1);
            scanf("%i", &massive[i][j]);
        }
    }
}

void print(int row, int column, int massive[row][column]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            printf("%i ", massive[i][j]);
        }
        printf("\n");
    }
}

int maxx(int row, int column, int massive[row][column]){
    int max = INT16_MIN;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (massive[i][j] > max){
                max = massive[i][j];
            }
        }
    }
    return max;
}

int minn(int row, int column, int massive[row][column]){
    int min = INT16_MAX;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            if (massive[i][j] < min){
                min = massive[i][j];
            }
        }
    }
    return min;
}

float avgg(int row, int column, int massive[row][column]){
    int sum = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            sum = sum + massive[i][j];
        }
    }
    return (float)sum / (float)(row * column);
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void diagonal(int side, int massive[side][side]){
    for (int i = 0; i < side; i++){
        for (int j = 0; j < side; j++){
            if (i == j){
                int other_diagonal_j = side - j - 1;
                swap(&massive[i][j],  &massive[i][other_diagonal_j]);
            }
        }
    }
}

void sort(int row, int column, int massive[row][column], int s){
    if (s == 1) {
        for (int u = 0; u < row; u++){
            bool swapped;
            for (int i = 0; i < column - 1; i++){
                swapped = false;
                for (int j = 0; j < column - i - 1; j++){
                    if (massive[u][j] < massive[u][j + 1]){
                        swap(&massive[u][j], &massive[u][j+1]);
                        swapped = true;
                    }
                }
                if (!swapped){
                    break;
                }
            }
        }
        
    } else if (s == 2) {
        for (int u = 0; u < row; u++){
            bool swapped;
            for (int i = 0; i < column - 1; i++){
                swapped = false;
                for (int j = 0; j < column - i - 1; j++){
                    if (massive[u][j] > massive[u][j + 1]){
                        swap(&massive[u][j], &massive[u][j+1]);
                        swapped = true;
                    }
                }
                if (!swapped){
                    break;
                }
            }
        }
    }
}



int main(){
    int row, column;
    printf("Moriin toog oruulna uu: ");
    scanf("%i", &row);
    printf("Bagana toog oruulna uu: ");
    scanf("%i", &column);

    int massive[row][column];

    int songolt;
    printf("Songoltoo oruulna uu: (1: garaas utga oruulna 2: random oor utga oruulna):  ");
    scanf("%i", &songolt);

    if (songolt == 1){
        garaas(row, column, massive);
    } else if (songolt == 2){
        random_utga(row, column, massive);
    } else {
        printf("Buruu songolt oruulsan baina.");
    }

    print(row, column, massive);

    printf("massive iin hamgiin ih element: %i\n", maxx(row, column, massive));
    printf("massive iin hamgiin baga element: %i\n", minn(row, column, massive));
    printf("massive iin dundaj: %f\n", avgg(row, column, massive));
    
    if (row == column){
        printf("Tanii massive kvadrat massive baina. Gol diagonaliig esreg diagonalaar solino.\n");
        print(row, column, massive);
        diagonal(row, massive);
        printf("\n");
        print(row, column, massive);
    } else{ 
        printf("Tanii massive kvadrat massive bish baina.\n1. 2d massive iig ihees baga ruu erembeleh.\n2. 2d massive iig bagaas ih ruu erembeleh.:   ");
        int songolt_2;
        scanf("%i", &songolt_2);
        if (songolt_2 == 1){
            sort(row, column, massive, 1);
        } else if (songolt_2 == 2){
            sort(row, column, massive, 2);
        } else {
            printf("Buruu utga oruulsan baina. \n");
        }
        print(row, column, massive);
    }


}