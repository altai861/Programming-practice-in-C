#include<stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BEGINNER 0
#define INTERMEDIATE 1
#define ADVANCED 2
#define MAXSIDE 20
#define MAXMINES 100
#define MOVESIZE 300 // (25 * 25 - 99)

int SIDE ; // tal
int MINES ; // mine nii too

// A Utility Function to check whether given cell (row, col)
// is a valid cell or not
bool isValid(int row, int col)
{
	// Returns true if row number and column number
	// is in range
	return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
}
// mine tei esehiig shalgana
bool isMine (int row, int col, char board[][MAXSIDE])
{
	if (board[row][col] == '*')
		return true;
	else
		return false;
}
// toglogchiin hodolgooniig avah
void makeMove(int *x, int *y)
{
	printf("Enter your move, (row, column) -> ");
	scanf("%d %d", x, y);
	return;
}
// Board hevleh function
void printBoard(char myBoard[][MAXSIDE])
{
	int i, j;

	printf ("   ");

	for (i=0; i<SIDE; i++)
		printf ("%2d ", i);

	printf ("\n");

	for (i=0; i<SIDE; i++)
	{
		printf ("%2d ", i);

		for (j=0; j<SIDE; j++)
			printf ("%2c ", myBoard[i][j]);
		printf ("\n");
	}
	return;
}
// A Function to count the number of
// mines in the adjacent cells
int countAdjacentMines(int row, int col, int mines[][2],
					char realBoard[][MAXSIDE])
{

	int i;
	int count = 0;

	/*
		Count all the mines in the 8 adjacent
		cells

			 N.W   N   N.E
			   \  |   /
			    \ |  /
			W----Cell----E
				/ |  \
			   /  |  \
			S.W   S    S.E

		Cell-->Current Cell (row, col)
		N --> North	 (row-1, col)
		S --> South	 (row+1, col)
		E --> East		 (row, col+1)
		W --> West		 (row, col-1)
		N.E--> North-East (row-1, col+1)
		N.W--> North-West (row-1, col-1)
		S.E--> South-East (row+1, col+1)
		S.W--> South-West (row+1, col-1)
	*/

	//----------- 1st Neighbour (North) ------------

		// Only process this cell if this is a valid one
		if (isValid (row-1, col) == true)
		{
			if (isMine (row-1, col, realBoard) == true)
			count++;
		}

	//----------- 2nd Neighbour (South) ------------

		// Only process this cell if this is a valid one
		if (isValid (row+1, col) == true)
		{
			if (isMine (row+1, col, realBoard) == true)
			count++;
		}

	//----------- 3rd Neighbour (East) ------------

		// Only process this cell if this is a valid one
		if (isValid (row, col+1) == true)
		{
			if (isMine (row, col+1, realBoard) == true)
			count++;
		}

	//----------- 4th Neighbour (West) ------------

		// Only process this cell if this is a valid one
		if (isValid (row, col-1) == true)
		{
			if (isMine (row, col-1, realBoard) == true)
			count++;
		}

	//----------- 5th Neighbour (North-East) ------------

		// Only process this cell if this is a valid one
		if (isValid (row-1, col+1) == true)
		{
			if (isMine (row-1, col+1, realBoard) == true)
			count++;
		}

	//----------- 6th Neighbour (North-West) ------------

		// Only process this cell if this is a valid one
		if (isValid (row-1, col-1) == true)
		{
			if (isMine (row-1, col-1, realBoard) == true)
			count++;
		}

	//----------- 7th Neighbour (South-East) ------------

		// Only process this cell if this is a valid one
		if (isValid (row+1, col+1) == true)
		{
			if (isMine (row+1, col+1, realBoard) == true)
			count++;
		}

	//----------- 8th Neighbour (South-West) ------------

		// Only process this cell if this is a valid one
		if (isValid (row+1, col-1) == true)
		{
			if (isMine (row+1, col-1, realBoard) == true)
			count++;
		}

	return (count);
}

// A Recursive Function to play the Minesweeper Game
bool playMinesweeperUtil(char myBoard[][MAXSIDE], char realBoard[][MAXSIDE], int mines[][2], int row, int col, int *movesLeft)
{

	// Base Case of Recursion
	if (myBoard[row][col] != '-')
		return (false);

	int i, j;

	// Mine iig neesen (hojigdono)
	if (realBoard[row][col] == '*')
	{
		myBoard[row][col]='*';

		for (i=0; i<MINES; i++)
			myBoard[mines[i][0]][mines[i][1]]='*';

		printBoard (myBoard);
		printf ("\nYou lost!\n");
		return (true) ;
	}

	else
	{
		// Calculate the number of adjacent mines and put it
		// on the board
		int count = countAdjacentMines(row, col, mines, realBoard);
		(*movesLeft)--;

		myBoard[row][col] = count + '0';

		if (!count)
		{
			/*
			Recur for all 8 adjacent cells

				N.W N N.E
				\ | /
					\ | /
				W----Cell----E
					/ | \
				/ | \
				S.W S S.E

			Cell-->Current Cell (row, col)
			N --> North	 (row-1, col)
			S --> South	 (row+1, col)
			E --> East		 (row, col+1)
			W --> West		 (row, col-1)
			N.E--> North-East (row-1, col+1)
			N.W--> North-West (row-1, col-1)
			S.E--> South-East (row+1, col+1)
			S.W--> South-West (row+1, col-1)
			*/

				//----------- 1st Neighbour (North) ------------

			// Only process this cell if this is a valid one
			if (isValid (row-1, col) == true)
			{
				if (isMine (row-1, col, realBoard) == false)
				playMinesweeperUtil(myBoard, realBoard, mines, row-1, col, movesLeft);
			}

			//----------- 2nd Neighbour (South) ------------

			// Only process this cell if this is a valid one
			if (isValid (row+1, col) == true)
			{
				if (isMine (row+1, col, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col, movesLeft);
			}

			//----------- 3rd Neighbour (East) ------------

			// Only process this cell if this is a valid one
			if (isValid (row, col+1) == true)
			{
				if (isMine (row, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col+1, movesLeft);
			}

			//----------- 4th Neighbour (West) ------------

			// Only process this cell if this is a valid one
			if (isValid (row, col-1) == true)
			{
				if (isMine (row, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row, col-1, movesLeft);
			}

			//----------- 5th Neighbour (North-East) ------------

			// Only process this cell if this is a valid one
			if (isValid (row-1, col+1) == true)
			{
				if (isMine (row-1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col+1, movesLeft);
			}

			//----------- 6th Neighbour (North-West) ------------

			// Only process this cell if this is a valid one
			if (isValid (row-1, col-1) == true)
			{
				if (isMine (row-1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row-1, col-1, movesLeft);
			}

			//----------- 7th Neighbour (South-East) ------------

			// Only process this cell if this is a valid one
			if (isValid (row+1, col+1) == true)
			{
				if (isMine (row+1, col+1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col+1, movesLeft);
			}

			//----------- 8th Neighbour (South-West) ------------

			// Only process this cell if this is a valid one
			if (isValid (row+1, col-1) == true)
			{
				if (isMine (row+1, col-1, realBoard) == false)
					playMinesweeperUtil(myBoard, realBoard, mines, row+1, col-1, movesLeft);
			}
		}

		return (false);
	}
}

// randomoor mine tavih function
void placeMines(int mines[][2], char realBoard[][MAXSIDE])
{
	bool mark[MAXSIDE*MAXSIDE];

	memset (mark, false, sizeof (mark));

	// buh mine bairluulagdtal davtana.
	for (int i=0; i<MINES; )
	{
		int random = rand() % (SIDE*SIDE);
		int x = random / SIDE;
		int y = random % SIDE;

		// boardiin ene nudend mine bhgu bl mine bairluulna
		if (mark[random] == false)
		{
			// Row Index of the Mine
			mines[i][0]= x;
			// Column Index of the Mine
			mines[i][1] = y;
			// mine bairluulna
			realBoard[mines[i][0]][mines[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}
	return;
}

// Togloom ehluuleh function
void initialise(char realBoard[][MAXSIDE], char myBoard[][MAXSIDE])
{
	// Initiate the random number generator so that
	// the same configuration doesn't arises
	srand(time(NULL));
	// buh nudiig mine gui gj onoono.
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
		{
			myBoard[i][j] = realBoard[i][j] = '-';
		}
	}
	return;
}
// mine ii bairlaliig hevleh function
void cheatMinesweeper (char realBoard[][MAXSIDE])
{
	printf ("The mines locations are-\n");
	printBoard (realBoard);
	return;
}

// A function to replace the mine from (row, col) and put
// it to a vacant space
void replaceMine (int row, int col, char board[][MAXSIDE])
{
	for (int i=0; i<SIDE; i++)
	{
		for (int j=0; j<SIDE; j++)
			{
				// Find the first location in the board
				// which is not having a mine and put a mine
				// there.
				if (board[i][j] != '*')
				{
					board[i][j] = '*';
					board[row][col] = '-';
					return;
				}
			}
	}
	return;
}

// togloom togloh function
void playMinesweeper ()
{
	// Initially the game is not over
	bool gameOver = false;

	char realBoard[MAXSIDE][MAXSIDE], myBoard[MAXSIDE][MAXSIDE];
	int movesLeft = SIDE * SIDE - MINES, x, y;//niit nudees miniig hassn uldegdel nudnuud
	int mines[MAXMINES][2]; // buh mine uudiin coordinate ig hadgalna

	initialise (realBoard, myBoard);

	placeMines (mines, realBoard);
	
	/* Mine ii bairshluudiig hevlene
	cheatMinesweeper(realBoard);*/

	// You are in the game until you have not opened a mine
	// So keep playing

	int currentMoveIndex = 0;
	while (gameOver == false)
	{
		printf ("Current Status of Board : \n");
		printBoard (myBoard);
		makeMove (&x, &y);

		// This is to guarantee that the first move is
		// always safe
		// If it is the first move of the game
		if (currentMoveIndex == 0)
		{
			// If the first move itself is a mine
			// then we remove the mine from that location
			if (isMine (x, y, realBoard) == true)
				replaceMine (x, y, realBoard);
		}

		currentMoveIndex ++;

		gameOver = playMinesweeperUtil (myBoard, realBoard, mines, x, y, &movesLeft);

		if ((gameOver == false) && (movesLeft == 0))
		{
			printf ("\nYou won !\n");
			gameOver = true;
		}
	}
	return;
}

// level ee songoh function
void chooseDifficultyLevel ()
{
	int level;
	int side;
	printf("8-20 side aa songonuu: ");
	do {
		scanf("%i", &side);
	} while (side < 8 && side > 20);

	printf ("Enter the Difficulty Level\n");
	printf ("Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n");
	printf ("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n");
	printf ("Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n");

	//begginer 
	scanf ("%d", &level);

	if (level == BEGINNER)
	{
		SIDE = side;
		MINES = (int)(side*side) * 10 / 100;
	}
	if (level == INTERMEDIATE)
	{
		SIDE = side;
		MINES = (int)(side*side) * 15 / 100;
	}
	if (level == ADVANCED)
	{
		SIDE = side;
		MINES = (int)(side*side) * 20 / 100;
	}
	return;
}
int main()
{								
	chooseDifficultyLevel (); /* Level ee songono.*/
	playMinesweeper ();
	return (0);
}

