
#include <conio.h>
#include "Board.h"


#include <cstdlib>

void clrscr() {
	system("cls"); // Clear screen for Windows
}

void Board::reset() {
	for (int i = 0; i < MAX_Y; i++) {
		memcpy(currentBoard[i], originalBoard[i], MAX_X + 1);
	}
}

void Board::print() const {
	for (int i = 0; i < MAX_Y - 1; i++) {
		std::cout << currentBoard[i] << '\n';
	}
	std::cout << currentBoard[MAX_Y - 1];
}

void Board::printScreen(const char screen[][MAX_X + 1]) const
{
	clrscr();
	for (int i = 0; i < MAX_Y - 1; i++) {
		std::cout << screen[i] << '\n';
	}
	std::cout << screen[MAX_Y - 1];
}
