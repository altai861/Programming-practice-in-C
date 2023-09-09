#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLUSH fflush(stdin)

void difficulty( void );
void beginner( void );
void intermediate( void );
void expert( void );
void minefield_generator( void );
void print_minefield( void );
void guess( void );
void boom( void );
void print_final_minefield( void );
void win( void );
void play_again( void );
void game_over( void );
void custom(void);

int x, y;
int M, N;
float diff;
int total_mines = 0;
int mines = 0;
int flags = 0;
int minefield[20][20];                                      //This 2-D array contains all of the mines, numbers and blank spaces
int blank_minefield[20][20];                                //This contains the minefield full of '|-|' characters
int final_minefield[20][20];




int main()
{
    difficulty();
    return 0;
}

void difficulty( void )                                     //Function for choosing the difficulty level
{
    diff = 0;
    while( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))        
    {
        printf("\t\tTa tuvshingee songono uu (1-3) or 4 bol Duriin hemjeetei :");   
        scanf("%f", &diff);
        FLUSH;
        if( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
        {
            printf("\t\t 1, 2, 3 , 4 iig oruulna uu !\n");
        }
    }   

    if( diff == 1 )                                         //If, else if and else statements that each go to the respective difficulty
    {
        beginner();
    }
    else if( diff == 2 )
    {
        intermediate();
    }
    else if( diff == 3 )
    {
        expert();
    }
    else if( diff == 4)
    {
        custom();
    }
}

void beginner( void )                                       //Gives the minefield the 'beginner' grid and mines
{
    M = 8;
    N = 8;
    total_mines = 10;
    minefield_generator();
    guess();
}

void intermediate( void )                                   //Gives the minefield the 'intermediate' grid and mines
{
    M = 16;
    N = 16;
    total_mines = 40;
    minefield_generator();
    guess();
}

void expert( void )                                         //Gives the minefield the 'expert' grid size and mines
{
    M = 20;
    N = 20;
    total_mines = 99;
    minefield_generator();
    guess();
}

void custom( void )
{
    M = 0;
    N = 0;
    total_mines = 0;
    printf("\t\tHemjeeg oruulna uu \n");
    printf("\t\t Baganiin utga:\n");
    scanf("%d", &M);
    printf("\t\tMoriin utga:\n");
    scanf("%d", &N);
    printf("\t\tHeden mine oruulah ve :\n");
    scanf("%d", &total_mines);
    minefield_generator();
    guess();
}

void minefield_generator( void )  {                          //Function that generates the minefield
	
	if(total_mines>M*N){
		system("cls");
	printf("Ta zuv utga oruulna uu !!! \n\n");
	custom();
	}


{	if(M<0 && N<0){
	system("cls");
	printf("Ta zuv utga oruulna uu !!! \n\n");
	custom();
}
    int i = 0, j = 0;

    srand( time( NULL ) );                                  //Starts the random no. generator

    while( j < N )                                          //Nested loop for making the blank minefield and final minefield
    {
        while( i < M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];        
            final_minefield[i][j] = minefield[i][j];        
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )                            //Randomly generates the mines into the minefield
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')                         //If statement that checks if there is a mine already there and doesn't place a mine if there is
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < M)
        {
            if( minefield[i][j] != '*')
            {
                minefield[i][j] = 0;
            }   
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}
}

void print_minefield(void)                                  // This function prints the minefield
{
    int i = 0, j = 0, z = 0;
    while( z < M )                                          // This while loop prints out the line of co-ordinates along the x axis of the minefield
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          // Loop that prints out each character in the minefield                         
    {   
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )                 // This changes any spaces with values of zero to the character 'B'
            {
                blank_minefield[i][j] = '0';                
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void guess( void )
{
    int q = 0, i=0, j=0, match=0;
    print_minefield();
    while( j < N )                                          // While loop for testing whether or not the user has cleared the minefield
    {
        while( i < M )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines))                 // If the user has cleared the minefield, the win() function is run
    {
        win();
    }
    printf("\nCoordinate oruulna uu :");
    scanf("%d %d", &x, &y);                                 // Reading in the co-ordinates for the guess
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nZuv utga oruulna uu \n");
        guess();
    }
    if( minefield[x][y] == '*' )                            // Runs the boom() function if the user selects a mine
    {
        boom();
    }
    if( blank_minefield[x][y] != '-' )
    {
        printf("\nUmnu ni hiisen utga baina \n");
        guess();
    }

    else                                                // Checks if the adjacent spaces are blank, then changes the values in the blank_minefield array. Because they are changed, they will now print out in the print_minefield function
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess();
    }
}

void boom( void )                                       // Runs the print_final_minefield function, then the play_again function                    
{
    print_final_minefield();
    printf("\n\t\tTa ( %d,%d )\n\t\t deer mine onoson baina.Ta hojigdloo", x, y);
    play_again();
}

void print_final_minefield( void )                      // Prints the minefield, showing where all of the mines are placed
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {   
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void win( void )                                        // Runs the play_again function
{
    printf("\n\n\n\t\t\tTa hojloo bayar hurgeye!!!!\n\n\n");
    play_again();
}

void play_again( void )                                 // Gives the user the option to play again
{
    char option[2];
    printf("\n\t\tDahiad togloh uu ? (T/U)?:");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'T') || (option[0] == 't'))        // Restarts the program from after the welcome message
    {	system("cls");
        difficulty();
    }
    else if( (option[0] == 'U') || (option[0] == 'u'))
    {
        game_over();
    }
    else
    {
        printf("Zuv utga oruulna uu ");
        system("cls");
        play_again();
    }
}

void game_over( void )                                  // Ends the program
{
    printf("\n\n\t\t MANAI TOGLOOMIIG TOGLOSOND BAYRLALAAA <#");
    exit(1);
}
