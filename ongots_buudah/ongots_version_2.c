#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 20

void make_board(char board[SIZE][SIZE]){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            board[i][j] = '.';
        }
    }
}

void print_board_tracker(char board1_track_2[SIZE][SIZE], char board2_track_1[SIZE][SIZE]){
    printf("\t\t\tPLAYER 1 \t\t\t\t\t\t\t\t\t\t\tPLAYER 2\n");
    printf("   ");
    for (int i = 1; i < 10; i++){
        printf(" %i ", i);
    }
    printf(" %i", 10);
    for (int i = 1; i < 11; i++){
        printf(" %i ", i);
    }
    printf("\t\t\t   ");
    for (int i = 1; i < 10; i++){
        printf(" %i ", i);
    }
    printf(" %i", 10);
    for (int i = 1; i < 11; i++){
        printf(" %i ", i);
    }
    printf("\n");
    for (int i = 0; i < 20; i++){
        if (i + 1 >= 10){
            printf(" %i", i + 1);
        } else {
            printf(" %i ", i + 1);
        }
        
        for (int j = 0; j < 20; j++){
            printf(" %c ", board1_track_2[i][j]);
        }
        printf("\t\t\t\t");
        if (i + 1 >= 10){
            printf(" %i", i + 1);
        } else {
            printf(" %i ", i + 1);
        }
        for (int j = 0; j < 20; j++){
            printf(" %c ", board2_track_1[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void print_board(char board[SIZE][SIZE]){
    printf("   ");
    for (int i = 1; i < 10; i++){
        printf(" %i ", i);
    }
    printf(" %i", 10);
    for (int i = 1; i < 11; i++){
        printf(" %i ", i);
    }
    printf("\n");
    for (int i = 0; i < 20; i++){
        if (i + 1 >= 10){
            printf(" %i", i + 1);
        } else {
            printf(" %i ", i + 1);
        }
        for (int j = 0; j < 20; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");

}

bool check(char c){
    if (c != 'T' && c != 'B'){
        return true;
    } else {
        return false;
    }
}

bool up_position(char board[SIZE][SIZE], int rand_x, int rand_y){
    if (rand_y + 1 >= SIZE || rand_y - 1 < 0 || rand_x + 1 >= SIZE || rand_x + 2 >= SIZE || rand_x + 3 >= SIZE){
        return false;
    } else {
        char left_arm = board[rand_x + 1][rand_y - 1];
        char mid_chest = board[rand_x + 1][rand_y];
        char right_arm = board[rand_x + 1][rand_y + 1];
        char stomach = board[rand_x + 2][rand_y];
        char left_leg = board[rand_x + 3][rand_y - 1];
        char hip = board[rand_x + 3][rand_y];
        char right_leg = board[rand_x + 3][rand_y + 1];
        if (check(left_arm) && check(mid_chest) && check(right_arm) && check(stomach) && check(left_leg) && check(hip) && check(right_leg)){
            return true;
        } else {
            return false;
        }
    }
}

bool right_position(char board[SIZE][SIZE], int rand_x, int rand_y){
    if (rand_y - 1 < 0 || rand_y - 2 < 0 || rand_y - 3 < 0 || rand_x - 1 < 0 || rand_x + 1 >= SIZE ){
        return false;
    } else {
        char left_arm = board[rand_x - 1][rand_y - 1];
        char mid_chest = board[rand_x][rand_y - 1];
        char right_arm = board[rand_x + 1][rand_y - 1];
        char stomach = board[rand_x][rand_y - 2];
        char left_leg = board[rand_x - 1][rand_y - 3];
        char hip = board[rand_x][rand_y - 3];
        char right_leg = board[rand_x + 1][rand_y - 3];
        if (check(left_arm) && check(mid_chest) && check(right_arm) && check(stomach) && check(left_leg) && check(hip) && check(right_leg)){
            return true;
        } else {
            return false;
        }
    }
}

bool left_position(char board[SIZE][SIZE], int rand_x, int rand_y){
     if (rand_x - 1 < 0 || rand_x + 1 >= SIZE || rand_y + 1 >= SIZE || rand_y + 2 >= SIZE || rand_y + 3 >= SIZE ){
        return false;
    } else {
        char left_arm = board[rand_x + 1][rand_y + 1];
        char mid_chest = board[rand_x][rand_y + 1];
        char right_arm = board[rand_x - 1][rand_y + 1];
        char stomach = board[rand_x][rand_y + 2];
        char left_leg = board[rand_x + 1][rand_y + 3];
        char hip = board[rand_x][rand_y + 3];
        char right_leg = board[rand_x - 1][rand_y + 3];
        if (check(left_arm) && check(mid_chest) && check(right_arm) && check(stomach) && check(left_leg) && check(hip) && check(right_leg)){
            return true;
        } else {
            return false;
        }
    }
}

bool down_position(char board[SIZE][SIZE], int rand_x, int rand_y){
    if (rand_y - 1 < 0 || rand_y + 1 >= SIZE || rand_x - 1 < 0 || rand_x - 2 < 0 || rand_x - 3 < 0){
        return false;
    } else {
        char left_arm = board[rand_x - 1][rand_y + 1];
        char mid_chest = board[rand_x - 1][rand_y];
        char right_arm = board[rand_x - 1][rand_y - 1];
        char stomach = board[rand_x - 2][rand_y];
        char left_leg = board[rand_x - 3][rand_y + 1];
        char hip = board[rand_x - 3][rand_y];
        char right_leg = board[rand_x - 3][rand_y - 1];
        if (check(left_arm) && check(mid_chest) && check(right_arm) && check(stomach) && check(left_leg) && check(hip) && check(right_leg)){
            return true;
        } else {
            return false;
        }
    }
}

void draw(char board[SIZE][SIZE], int x, int y, int pos){
    if (pos == 1){
        board[x][y] = 'T';
        board[x + 1][y - 1] = 'B';
        board[x + 1][y] = 'B';
        board[x + 1][y + 1] = 'B';
        board[x + 2][y] = 'B';
        board[x + 3][y - 1] = 'B';
        board[x + 3][y] = 'B';
        board[x + 3][y + 1] = 'B';
        
    } else if (pos == 2){
        board[x][y] = 'T';
        board[x - 1][y - 1] = 'B';
        board[x][y - 1] = 'B';
        board[x + 1][y - 1] = 'B';
        board[x][y - 2] = 'B';
        board[x - 1][y - 3] = 'B';
        board[x][y - 3] = 'B';
        board[x + 1][y - 3] = 'B';

    } else if (pos == 3){
        board[x][y] = 'T';
        board[x + 1][y + 1] = 'B';
        board[x][y + 1] = 'B';
        board[x - 1][y + 1] = 'B';
        board[x][y + 2] = 'B';
        board[x - 1][y + 3] = 'B';
        board[x][y + 3] = 'B';
        board[x + 1][y + 3] = 'B';

    } else if (pos == 4){
        board[x][y] = 'T';
        board[x - 1][y + 1] = 'B';
        board[x - 1][y] = 'B';
        board[x - 1][y - 1] = 'B';
        board[x - 2][y] = 'B';
        board[x - 3][y + 1] = 'B';
        board[x - 3][y] = 'B';
        board[x - 3][y - 1] = 'B';
    }
}
void insert(int new[], int i){
    int j = 0;
    while (true){
        if (!new[j]){
            new[j] = i;
            break;
        }
        j++;
    }
}

int len(int too){
    int i = too;
    int length = 0;
    while (i > 0){
        length += 1;
        i = i / 10;
    }
    return length;
}

int kth_element(int random_pos, int too){
    int digit = (too / (int)pow(10, random_pos - 1)) % 10;
    return digit;
}

bool single_ship_drawer(char board[20][20]){
    srand(time(NULL));
    int rand_x = (rand() % 20);
    int rand_y = (rand() % 20);
    if (board[rand_x][rand_y] != 'T' && board[rand_x][rand_y] != 'B'){
        int possible_positions = 0;
        if (up_position(board, rand_x, rand_y)){
            possible_positions = possible_positions * 10 + 1;
        }if (right_position(board, rand_x, rand_y)){
            possible_positions = possible_positions * 10 + 2;
        }if (left_position(board, rand_x, rand_y)){
            possible_positions = possible_positions * 10 + 3;
        }if (down_position(board, rand_x, rand_y)){
            possible_positions = possible_positions * 10 + 4;
        }
            
        int length = len(possible_positions);
        if (length > 0){
            int random_pos = rand() % length + 1;
            int pos = kth_element(random_pos, possible_positions);
            draw(board, rand_x, rand_y, pos);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void battleships_drawer(char board[SIZE][SIZE]){
    
    int number_of_ships = 0;
    while (number_of_ships < 8){
        if (single_ship_drawer(board)){
            number_of_ships++;
        } else {
            continue;
        }
    }
}

bool check_win(char board[SIZE][SIZE]){
    int sonoson_ongots_counter = 0;
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if (board[i][j] == 'S'){
                sonoson_ongots_counter++;
            }
        }
    }
    if (sonoson_ongots_counter == 8){
        return true;
    } else {
        return false;
    }
}

void menu(){
    printf("Zaavar : Toglogch bur 3 udaa eeljilj buudna.\n");
    printf("Biyiig onovol U garna. Tolgoig onovol S useg garj irj sonono.\n");
    printf("Hooson bol X garj irnee.\n");
}

int main(){
    char board1[SIZE][SIZE];
    char board2[SIZE][SIZE];
    char player1_board2_tracker[SIZE][SIZE];
    char player2_board1_tracker[SIZE][SIZE];

    make_board(board1);
    make_board(board2);

    make_board(player1_board2_tracker);
    make_board(player2_board1_tracker);

    menu();

    battleships_drawer(board1);
    battleships_drawer(board2);


    //print_board(board1);
    //print_board(board2);

    while (true){
        
        int buudsan_too_player1 = 0;
        while (buudsan_too_player1 < 3){
            if (check_win(player1_board2_tracker)){
                printf("Ylagch player1 bayr hurgie.\n");
                exit(0);
            }
            print_board_tracker(player1_board2_tracker, player2_board1_tracker);
            int x, y;
            printf("PLAYER 1 BUUDNA.\n");
            do {
                printf("x: ");
                scanf("%i", &x);
            } while (x < 1 || x > 20);
            
            do {
                printf("y: ");
                scanf("%i", &y);
            } while (y < 1 || y > 20);
            
            if (player1_board2_tracker[x - 1][y - 1] == '.'){
                if (board2[x - 1][y - 1] == 'B'){
                    player1_board2_tracker[x - 1][y - 1] = 'U';
                } else if (board2[x - 1][y - 1] == 'T'){
                    player1_board2_tracker[x - 1][y - 1] = 'S';
                } else {
                    player1_board2_tracker[x - 1][y - 1] = 'X';
                }
                buudsan_too_player1++;
            } else {
                printf("Ta ene nudiig buudsan baina. \n");
            }
        }

        int buudsan_too_player2 = 0;
        while (buudsan_too_player2 < 3){
            if (check_win(player2_board1_tracker)){
                printf("Ylagch player2 bayr hurgie.\n");
                exit(0);
            }
            print_board_tracker(player1_board2_tracker, player2_board1_tracker);
            int x, y;
            printf("PLAYER 2 BUUDNA.\n");
            do {
                printf("x: ");
                scanf("%i", &x);
            } while (x < 1 || x > 20);
            
            do {
                printf("y: ");
                scanf("%i", &y);
            } while (y < 1 || y > 20);
            
            if (player2_board1_tracker[x - 1][y - 1] == '.'){
                if (board1[x - 1][y - 1] == 'B'){
                    player2_board1_tracker[x - 1][y - 1] = 'U';
                } else if (board1[x - 1][y - 1] == 'T'){
                    player2_board1_tracker[x - 1][y - 1] = 'S';
                } else {
                    player2_board1_tracker[x - 1][y - 1] = 'X';
                }
                buudsan_too_player2++;
            } else {
                printf("Ta ene nudiig buudsan baina. \n");
            }
        }
    }
    
    
    return 0;
}