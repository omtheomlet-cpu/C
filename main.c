// Tic Tac Toe game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define SIZE 3

char board[SIZE][SIZE];

void drawBoard();
void pvp();
void xMove();
void oMove();
void isDraw();
void isWin();
void xWin();
void oWin();
void cvp();
void compMove();
void compMoveX();

int main() {

	int choice;

	// Seed the time: 
	srand(time(NULL));

	// To initialize the board: 
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			board[i][j] = ' ';
		}
	}

	printf("Welcome to the tic tac toe game!\n");

	printf("++++++++++++++++++++++++++++++++++++++\n");
	printf("Please choose: \n");
	printf("1. Player vs player\n");
	printf("2. Player vs computer\n");
	printf("Enter chioce: ");
	scanf("%d", &choice);

	if(choice == 1) {
		pvp();
	} else if(choice == 2) {
		cvp();
	} else {
		printf("Invalid choice.\n");
	}

	return 0;
}

void drawBoard() {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			if((i == 0 && j == 2) ||
				(i == 1 && j == 2) ||
				(i == 2 && j == 2)) {
				if(i == 2 && j == 2) {
					printf(" %c \n", board[i][j]);
				} else {
					printf(" %c \n", board[i][j]);
					printf("---+---+---\n");
				}
			} else {
				printf(" %c |", board[i][j]);
			}
		}	
	}
}

void pvp() {
	while(1) {
		drawBoard();
		xMove();
		isWin();
		isDraw();
		oMove();
		isWin();
		isDraw();
	}
}

void xMove() {
	int row, col;
	while(1) {
		printf("X's turn: \n");
		printf("Enter row: ");
		scanf("%d", &row);
		printf("Enter column: ");
		scanf("%d", &col);
		if(row >= 1 && col >= 1 && row < 4 && col < 4 && board[row - 1][col - 1] == ' ') {
			board[row - 1][col - 1] = 'X';
			drawBoard();
			printf("X played at row %d and column %d!\n", row, col);
			break;
		} else {
			printf("Invalid move. Please try again: \n");
		}
	}
}

void oMove() {
	printf("O's turn: \n");
	int row, col;
	while(1) {
		printf("Enter row: ");
		scanf("%d", &row);
		printf("Enter column: ");
		scanf("%d", &col);
		if(row >= 1 && col >= 1 && row < 4 && col < 4 && board[row - 1][col - 1] == ' ') {
			board[row - 1][col - 1] = 'O';
			drawBoard();
			printf("O played at row %d and column %d!\n", row, col);
			break;
		} else {
			printf("Invalid move. Please try again: \n");
		}
	}
}

void isDraw() {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			if(board[i][j] == ' ') {
				return;
			}
		}
	}
	printf("=================================\n");
	drawBoard();
	printf("This game ended in a draw!\n");
	exit(0);
}

void isWin() {
	// Row Check: 
	for(int temp = 0; temp < SIZE; temp++) {
		if(board[temp][1] != ' ' && board[temp][0] == board[temp][1] && board[temp][1] == board[temp][2]) {
			if(board[temp][1] == 'X') {
				xWin();
			} else {
				oWin();
			}
		}
	}
	
	// Column check:
	for(int temp = 0; temp < SIZE; temp++) {
		if(board[1][temp] != ' ' && board[0][temp] == board[1][temp] && board[1][temp] == board[2][temp]) {
			if(board[1][temp] == 'X') {
				xWin();
			} else {
				oWin();
			}
		}
	}

	// Manual Diagonal check:
	if((board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
	   (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
		if(board[1][1] == 'X') {		
			xWin();
		} else {
			oWin();
		}
	}
}

void xWin() {
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	drawBoard();
	printf("X has won this game!\n");
	exit(0);
}

void oWin() {
	printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	drawBoard();
	printf("O has won this game!\n");
	exit(0);
}

void cvp() {
	int choice;
	while(1) {
		printf("What do you want to play as? \n");
		printf("1. X\n");
		printf("2. O\n");
		scanf("%d", &choice);

		if(choice == 1) {
			while(1) {
				drawBoard();
				xMove();
				isWin();
				isDraw();
				compMove();
				isWin();
				isDraw();
			}
		} else if(choice == 2) {
			while(1) {
				drawBoard();
				oMove();
				isWin();
				isDraw();
				compMoveX();
				isWin();
				isDraw();
			}
		} else {
			printf("Invalid choice. Please try again: \n");
		}
	}
}

void compMove() {
	int row, col;
	while(1) {
		row = rand() % SIZE;
		col = rand() % SIZE;
		if(board[row][col] == ' ') {
			board[row][col] = 'O';
			drawBoard();
			printf("The computer played at row %d and column %d!\n", row + 1, col + 1);
			return;
		}
	}
}

void compMoveX() {
	int row, col;
	while(1) {
		row = rand() % SIZE;
		col = rand() % SIZE;
		if(board[row][col] == ' ') {
			board[row][col] = 'X';
			drawBoard();
			printf("The computer played at row %d and column %d!\n", row + 1, col + 1);
			return;
		}
	}
}