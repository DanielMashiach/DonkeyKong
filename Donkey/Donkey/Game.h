#pragma once

#include <iostream>		//for cout
#include <conio.h>		//for _kbhit(), _getch()
#include <Windows.h>	//for Sleep and colors
#include "utils.h"

#include "Mario.h"
class Game
{
	static constexpr int DEAD_MARIO = 0;
	static constexpr int FULL_LIVES = 3;
	static constexpr int EXPLOSION_RADIUS = 2;

	bool playing_mario = true;							// True = while mario has more than 0 lives
	bool exit_game = false;								// False = while EXIT_GAME hasn't been pressed

	Board board;
	Mario mario;

public:
	Game():mario(board){}
	//void showInstructions();
	void run();
	//void setStartingGame();
	//void stopGame();
	//bool menu();												// Displays the game menu and handles user input to start or quit the game
	//void pauseGame();											// Pauses the game when a 
	void startGame();
	void updateActionByKeys(int key);

	bool wonTheLevel();

};



