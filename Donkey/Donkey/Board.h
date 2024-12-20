#pragma once
#include <cstring> //for memcpy
#include <iostream>
#include <conio.h>
#include <cstdlib>

class Board
{
	static constexpr int MAX_X = 80;
	static constexpr int MAX_Y = 25;
	const char* originalBoard[MAX_Y] = {
		// 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", // 0
		  "Q  *   *                                                                       Q", // 1
		  "Q * * * *                                $                                     Q", // 2
		  "Q  *   *                 ================================                      Q", // 3
		  "Q   * *                     H            &            H                        Q", // 4
		  "Q    *                      H     ===============     H                        Q", // 5
		  "Q                           H                         H                        Q", // 6
		  "Q                           H                         H                        Q", // 7
		  "Q                           H                         H                        Q", // 8
		  "Q      <<<=======================<<           >>>====================>>>       Q", // 9
		  "Q                 H                                                   H        Q", // 10
		  "Q                 H                                                   H        Q", // 11
		  "Q                 H                                                   H        Q", // 12
		  "Q                 H                                                   H        Q", // 13
		  "Q     >>==========================                     <<=================     Q", // 14
		  "Q          H                                                       H           Q", // 15
		  "Q          H                                                       H           Q", // 16
		  "Q          H                                                       H           Q", // 17
		  "Q          H                                                       H           Q", // 18
		  "Q      =========>>===========>>===========               <<==================  Q", // 19
		  "Q                 H                H                        H                  Q", // 20
		  "Q                 H                H                        H                  Q", // 21
		  "Q                 H                H                        H                  Q", // 22
		  "Q==============================================================================Q", // 23
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"  // 24
	};

	char start_screen[MAX_Y][MAX_X + 1] = {
		//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
			"********************************************************************************", //0
			"*                                                                              *", //1
			"*                                                                              *", //2
			"*                                                                              *", //3
			"*		  ____   ___  _   _ _  _________   __  _  _____  _   _  ____            *", //4
			"*		 |  _ \ / _ \| \ | | |/ | ____\ \ / / | |/ / _ \| \ | |/ ___|           *", //5
			"*		 | | | | | | |  \| | ' /|  _|  \ V /  | ' | | | |  \| | |  _            *", //6
			"*		 | |_| | |_| | |\  | . \| |___  | |   | . | |_| | |\  | |_| |           *", //7
			"*		 |____/ \___/|_| \_|_|\_|_____| |_|   |_|\_\___/|_| \_|\____|           *", //8
			"*                                                                              *", //9
			"*                                                                              *", //10
			"*                                                                              *", //11
			"*          (1) Start new game                                                  *", //12
			"*          (8) Show instructions and keys                                      *", //13
			"*          (9) Exit                                                            *", //14
			"*                                                                              *", //15
			"*                                                                              *", //16
			"*                                                                              *", //17
			"*                                                                              *", //18
			"*                                                                              *", //19
			"*                                                                              *", //20
			"*	                                                                            *", //21
			"*                                                                              *", //22
			"*                                                                              *", //23
			"********************************************************************************"  //24
	};

	char winning_screen[MAX_Y][MAX_X + 1] = {
		// 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ", // 0
		  "Q                       __        _____ _   _ _   _ _____ ____                 Q", // 1
		  "Q                       \ \      / |_ _| \ | | \ | | ____|  _ \                Q", // 2
		  "Q                        \ \ /\ / / | ||  \| |  \| |  _| | |_) |               Q", // 3
		  "Q                         \ V  V /  | || |\  | |\  | |___|  _ <                Q", // 4
		  "Q                          \_/\_/  |___|_| \_|_| \_|_____|_| \_\               Q", // 5
		  "Q                                                                              Q", // 6
		  "Q                                                                              Q", // 7
		  "Q                                                                              Q", // 8
		  "Q                                                                              Q", // 9
		  "Q                                                                              Q", // 10
		  "Q                                                                              Q", // 11
		  "Q                                                                              Q", // 12
		  "Q                                                                              Q", // 13
		  "Q                                                                              Q", // 14
		  "Q                               YOU SAVED PAULINE!                             Q", // 15
		  "Q                                                                              Q", // 16
		  "Q                                                                              Q", // 17
		  "Q                                                                              Q", // 18
		  "Q                                                                              Q", // 19
		  "Q                                                                              Q", // 20
		  "Q                                                                              Q", // 21
		  "Q                                                                              Q", // 22
		  "Q                                                                              Q", // 23
		  "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"  // 24
	};


	char currentBoard[MAX_Y][MAX_X + 1]; // +1 for null terminator

public:
	void reset();
	void print() const;
	// This function resets the board to its original state
	void printScreen(const char screen[][MAX_X + 1]) const;
	char getChar(int x, int y) const {
		return currentBoard[y][x];
	}
	const char(&getStartBoard() const)[MAX_Y][MAX_X + 1]{ return start_screen; }
	const char(&getGameBoard() const)[MAX_Y][MAX_X + 1]{ return currentBoard; }
	const char(&getWinningBoard() const)[MAX_Y][MAX_X + 1]{ return winning_screen; }	
};


