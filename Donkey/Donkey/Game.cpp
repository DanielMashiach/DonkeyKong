#include "Game.h"

// Manages the overall flow of the game
void Game::run()
{
	system("mode con cols=80 lines=25");			// Set the console size to be 80X25
	ShowConsoleCursor(false);						// Hides the console cursor to improve visual appearance during the game

	//board.printScreen(board.getStartBoard());		// Displays the starting board on the screen
	//bool playing = true;

	//while (playing)									// Main game loop: keeps running while the game is active
	//	playing = menu();

	//clrscr();
	startGame();
}

// Displays the game menu and handles user input to start or quit the game
//bool Game::menu()
//{
//	if (_kbhit())									// Checks if a key has been pressed
//	{
//		int key = _getch();							// Reads the key that was pressed
//		switch (key) {
//		case((int)GameCon::eKeys::START_NEW_GAME):					// User pressed the key to start a new game
//			startGame();
//			break;
//		case((int)GameCon::eKeys::INSTRUCTIONS):				// User pressed the key to view instructions
//			showInstructions();
//			break;
//		case((int)GameCon::eKeys::EXIT_GAME):       			// User pressed the key to exit the game
//			board.printScreen(board.getGoodByeBoard());
//			Sleep(1000);
//			return false;							// Exit the menu loop and terminate the game
//		}
//	}
//	return true;
//}

void Game::startGame() {
	ShowConsoleCursor(false);
	board.reset();
	board.printScreen(board.getGameBoard());
	char key='\0';
	while (mario.getLives() != 0 ) {
		mario.printLives();
		mario.drawMario(); 
		if (wonTheLevel())
			break;
		if (_kbhit())
		{
			
			key = _getch();

			updateActionByKeys(key);
		}
		Sleep(150);
		mario.eraseMario();
		mario.move();
	}
}
// Updates Mario's actions based on key presses from the user
void Game::updateActionByKeys(int key) 
{
	if (key ==(int)GameCon::eKeys:: EXIT_GAME)	 				// If the key corresponds to the "Exit Game" action
	{
		exit_game = true;
	}
	//else if (key == (int)GameCon::eKeys::PAUSE)	 				// If the key corresponds to "Pause Game"
	//{
	//	pauseGame();
	//}
	else { mario.keyPressed(key); }	// For all other keys, pass the key to Mario's keyPressed handler
}

// Checks if Mario successfully completed the level
bool Game::wonTheLevel()
{
	if (mario.getIfWon())
	{
		
		board.printScreen(board.getWinningBoard());
		Sleep(2000);
		return true;
	}
	else
		return false;
}