#pragma once

#include "Point.h"
#include <Windows.h>
#include "utils.h"

using namespace std;

class Mario
{
	Point myMario;
	static constexpr char MARIO='@';
	static constexpr int MARIO_START_X = 1;
	static constexpr int MARIO_START_Y = 22;
	static constexpr int HIGH_FALL = 5;
	static constexpr char keys[] = {'w','a','x','d','s'};
	static constexpr size_t numKeys = sizeof(keys) / sizeof(keys[0]);
	enum eJump{ UPRIGHT, DOWNRIGHT, UPLEFT, DOWNLEFT };
	static constexpr GameCon::Direction jumpDirections[] = { {1,-1},{1,1},{-1,-1},{-1,1} };
	static constexpr int rightJump[] = {UPRIGHT,DOWNRIGHT };
	static constexpr int leftJump[] = { UPLEFT,DOWNLEFT };
	static constexpr int regularJump[] = { (int)GameCon::eDir::UP,(int)GameCon::eDir::DOWN }; 
	GameCon::Direction dir{ 0, 0 }; // current direction: dir.x, dir.y 
	GameCon::Direction prevDir{ 0, 0 }; // current direction: dir.x, dir.y 
	int lives = 3;
	int fallCounter = 0;
	int jumpStep = 0;
	bool isWon = FALSE;
	int i = 0;

	// Enumeration for Mario's possible states
	enum class MarioState {
		ClimbingUP,
		ClimbingDown,
		Jumping,
		Falling,
		Walking_or_Staying
	};
	MarioState state = MarioState::Walking_or_Staying;

	// Characters surrounding Mario
	char ch_curr = ' ', ch_below = ' ', two_ch_below = ' ',ch_above = ' ', ch_left = ' ', ch_right = ' ';

	char prevChar = ' ';


public:
	Mario(Board& board) {
		myMario.setXY(MARIO_START_X, MARIO_START_Y);
		myMario.setBoard(board);
	}
	void drawMario() {
		myMario.draw(MARIO);
	}
	void eraseMario() {															// Erase Mario's current position from the screen and update the board
		myMario.erase();
	}

	void setStartingMario();
	void keyPressed(char key);
	void changeDir(int dirIndex);
	void skip();
	bool isAboveFloor();
	bool isUnderneathFloor();
	bool isOnLadder() const;
	int getLives() { return lives; }
	void died() { --lives; }
	void move();
	void jump();
	void checkState();
	void updateByState();

	bool isClimbingUp();
	void climbUp();
	bool isClimbingDown();
	void climbDown();
	void walkOrStay();
	bool isJumping();
	bool isFalling();
	void fall();
	void handleIlligalMove();
	void updateNextMove();
	void updatePreviousDir() { prevDir = dir; }									// Function to update the Mario's previous direction to become the current (similar to previous_dir = dir)
	void updatePreviousChar() { prevChar=ch_curr; }
	void printLives();
	bool getIfWon() { return isWon; }

};

