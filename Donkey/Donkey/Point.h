#pragma once
#include <iostream>

#include "utils.h"
#include "Board.h"
#include "GameCon.h"

class Point
{
	int x, y;
	Board* pBoard = nullptr;
	char underlyingChar = ' '; // Character under point's current position



public:
	void setXY(int _x, int _y);
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setUnderlyingChar(char c) { underlyingChar = c; }
	char getUnderlyingChar() { return underlyingChar; }

	Board* getBoard() {
		return pBoard;
	}
	void draw(char c) const {
		gotoxy(x, y);
		std::cout << c;
		std::cout.flush(); // Ensure output is flushed immediately 
	}
	void erase() {
		draw(pBoard->getChar(x, y));
	}
	void setBoard(Board& board) {
		pBoard = &board;
	}

};

