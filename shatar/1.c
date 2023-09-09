#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[8][8];

void make_board(char board[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            board[i][j] = '.';
        }
    }
}

void print_board(char board[8][8]){
    for (int i = 0; i < 8; i++){
        printf(" %i ", 8 - i);
        for (int j = 0; j < 8; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("   ");
    for (int i = 1; i < 9; i++){
        printf(" %i ", i);
    }

    printf("\n");
}

void place_horses_and_boys(char board[8][8]){
    for(int i = 0; i < 8; i++){
        board[6][i] = 'H';
        board[1][i] = 'X';
    };
    
    board[0][1] = 'A';
    board[0][6] = 'A';
    board[7][1] = 'M';
    board[7][6] = 'M';

}

bool check_element(int x, int y){
    if (board[x][y] != 'M' && board[x][y] != 'H'){
        return false;
    } else {
        return true;
    }
}
bool check_element_black(int x, int y){
    if (board[x][y] != 'X' && board[x][y] != 'A'){
        return false;
    } else {
        return true;
    }
}

bool mori(int rx, int ry, int dx, int dy){
    if (((rx - 1 == dx && ry - 2 == dy) || (rx - 2 == dx && ry - 1 == dy) || (rx - 2 == dx && ry + 1 == dy) || (rx - 1 == dx && ry + 2 == dy) || (rx + 1 == dx && ry + 2 == dy) || (rx + 2 == dx && ry + 1 == dy) || (rx + 2 == dx && ry - 1 == dy) || (rx + 1 == dx && ry - 2 == dy)) && (board[dx][dy] == '.' || board[dx][dy] == 'A' || board[dx][dy] == 'X')){
        return true;
    } else {
        return false;
    }

}
bool mori_black(int rx, int ry, int dx, int dy){
    if (((rx - 1 == dx && ry - 2 == dy) || (rx - 2 == dx && ry - 1 == dy) || (rx - 2 == dx && ry + 1 == dy) || (rx - 1 == dx && ry + 2 == dy) || (rx + 1 == dx && ry + 2 == dy) || (rx + 2 == dx && ry + 1 == dy) || (rx + 2 == dx && ry - 1 == dy) || (rx + 1 == dx && ry - 2 == dy)) && (board[dx][dy] == '.' || board[dx][dy] == 'M' || board[dx][dy] == 'H')){
        return true;
    } else {
        return false;
    }

}

bool check_if_theres_piece(int rx, int dx, int ry){
    for (int i = dx + 1; i < rx; i++){
        if (board[i][ry] != '.'){
            return false;
        }
    }
    return true;
}
bool check_if_theres_piece_black(int rx, int dx, int ry){
    for (int i = rx + 1; i < dx; i++){
        if (board[i][ry] != '.'){
            return false;
        }
    }
    return true;
}

bool huu(int rx, int ry, int dx, int dy){
    if (rx == 6){
        if (((rx - 1 == dx && ry == dy) || (rx - 2 == dx && ry == dy)) && (board[dx][dy] == '.') && check_if_theres_piece(rx, dx, ry)){
            return true;
        }else if ((rx - 1 == dx) && ((ry + 1 == dy) || (ry - 1 == dy)) && (board[dx][dy] == 'X' || board[dx][dy] == 'A')) {
            return true;
        }
         else {
            return false;
        }
    } else {
        if((rx - 1 == dx && ry == dy) && (board[dx][dy] == '.') && check_if_theres_piece(rx, dx, ry)){
            return true;
        }else if ((rx - 1 == dx) && ((ry + 1 == dy) || (ry - 1 == dy)) && (board[dx][dy] == 'X' || board[dx][dy] == 'A')) {
            return true;
        }
         else {
            return false;
        }
    }
    
}
bool huu_black(int rx, int ry, int dx, int dy){
    if (rx == 1){
        if (((rx + 1 == dx && ry == dy) || (rx + 2 == dx && ry == dy)) && (board[dx][dy] == '.') && check_if_theres_piece_black(rx, dx, ry)){
            return true;
        } else if ((rx + 1 == dx) && ((ry + 1 == dy) || (ry - 1 == dy)) && (board[dx][dy] == 'H' || board[dx][dy] == 'M')) {
            return true;
        }
         else {
            return false;
        }

    } else {
        if((rx + 1 == dx && ry == dy) && (board[dx][dy] == '.') && check_if_theres_piece(rx, dx, ry)){
            return true;
        } else if ((rx + 1 == dx) && ((ry + 1 == dy) || (ry - 1 == dy)) && (board[dx][dy] == 'H' || board[dx][dy] == 'M')) {
            return true;
        } 
        else {
            return false;
        }
    }
    
}

bool move_element(int rx, int ry, int dx, int dy){
    if (board[rx][ry] == 'M'){
        if (mori(rx, ry, dx, dy)){
            board[rx][ry] = '.';
            board[dx][dy] = 'M';
            return true;
        } else {
            printf("Buruu nuudel oruulsan baina.\n");
            return false;
        }
    } else if (board[rx][ry] == 'H'){
        if (huu(rx, ry, dx, dy)){
            board[rx][ry] = '.';
            board[dx][dy] = 'H';
            return true;
        } else {
            printf("Buruu nuudel oruulsan baina. \n");
            return false;
        }
    }
    return false;
}

bool move_element_black(int rx, int ry, int dx, int dy){
    if (board[rx][ry] == 'A'){
        if (mori_black(rx, ry, dx, dy)){
            board[rx][ry] = '.';
            board[dx][dy] = 'A';
            return true;
        } else {
            printf("Buruu nuudel oruulsan baina.\n");
            return false;
        }
    } else if (board[rx][ry] == 'X'){
        if (huu_black(rx, ry, dx, dy)){
            board[rx][ry] = '.';
            board[dx][dy] = 'X';
            return true;
        } else {
            printf("Buruu nuudel oruulsan baina. \n");
            return false;
        }
    }
    return false;
}

bool check_winner_white(char board[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == 'H' || board[i][j] == 'M'){
                return false;
            }
        }
    }
    return true;
}

bool check_winner_black(char board[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == 'A' || board[i][j] == 'X'){
                return false;
            }
        }
    }
    return true;
}



int main(){
    make_board(board);
    place_horses_and_boys(board);
    while (true){
        while (true){
            if (check_winner_white(board)){
                printf("Har tal yllaa. \n");
                exit(0);
            }
            
            print_board(board);
            printf("Ali elementee hodolgoh ve (tsagaan): x y: ");
            int x, y;
            do{
                scanf("%i %i", &x, &y);
            } while (x < 1 || x > 8 || y < 1 || y > 8);

            int rx = 8 - x;
            int ry = y - 1;

            if (check_element(rx, ry)){
                int dx, dy;
                printf("Haashaa nuuh ve: x y: ");
                do {
                    scanf("%i %i", &dx, &dy); 
                } while (dx < 1 || dx > 8 || dy < 1 || dy > 8);
                dx = 8 - dx;
                dy = dy - 1;
                if (move_element(rx, ry, dx, dy)){
                    break;
                } else {
                    continue;
                }
            } else {
                printf("Ene hooson buudal baina. \n");
            }
        }
        while (true){
            if (check_winner_black(board)){
                printf("Tsagaan tal yllaa. \n");
                exit(0);
            }
            print_board(board);
            printf("Ali elementee hodolgoh ve (har): x y: ");
            int x, y;
            do{
                scanf("%i %i", &x, &y);
            } while (x < 1 || x > 8 || y < 1 || y > 8);

            int rx = 8 - x;
            int ry = y - 1;

            if (check_element_black(rx, ry)){
                int dx, dy;
                printf("Haashaa nuuh ve: x y: ");
                do {
                    scanf("%i %i", &dx, &dy); 
                } while (dx < 1 || dx > 8 || dy < 1 || dy > 8);
                dx = 8 - dx;
                dy = dy - 1;
                if (move_element_black(rx, ry, dx, dy)){
                    break;
                } else {
                    continue;
                }
                
            } else {
                printf("Ene hooson buudal baina. \n");
            }
        }
        
        
        
    }
    
    return 0;
}

