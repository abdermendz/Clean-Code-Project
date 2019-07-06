#pragma once
#include "Board.h"


class Game
{
private:
	Board playBoard;
	char playerTurn;
public:
	Game();
	~Game() {}
	void Play();
	bool isGameOver();
	void switchTurns();
	void getNextMove(Piece* aBoard[8][8]);
	char getPlayerTurn() const;
};
Game::Game() : playerTurn('W') {}

char Game::getPlayerTurn() const
{
	return playerTurn;
}

void Game::getNextMove(Piece* aBoard[8][8])
{
	bool canMove = false;
	do
	{
		playBoard.printBoard();

		cout <<playerTurn<< " enter's move: ";
		size_t stCoord;
		cin >> stCoord;
		size_t stRowCoord = (stCoord % 10) - 1;
		size_t stColCoord = (stCoord / 10) - 1;

		cout << "To : ";
		size_t endCoord;
		cin >> endCoord;
		size_t endRowCoord = (endCoord % 10) - 1;
		size_t endColCoord = (endCoord / 10) - 1;

		if ((stRowCoord <= 7 && stRowCoord >= 0) && (stColCoord <= 7 && stColCoord >= 0) && (endRowCoord <= 7 && endRowCoord >= 0)
			&& (endColCoord <= 7 && endColCoord >= 0))
		{
			Piece* currentPiece = aBoard[stRowCoord][stColCoord];
			if ((currentPiece != 0) && (currentPiece->getColor() == playerTurn))
			{
				if (currentPiece->isMoveCorect(stRowCoord, stColCoord, endRowCoord, endColCoord, aBoard))
				{
					Piece* tmp = aBoard[endRowCoord][endColCoord];
					aBoard[endRowCoord][endColCoord] = aBoard[stRowCoord][stColCoord];
					aBoard[stRowCoord][stColCoord] = 0;

					if (!playBoard.isCheck(playerTurn))
					{
						delete tmp;
						canMove = true;
					}
					else
					{
						aBoard[stRowCoord][stColCoord] = aBoard[endRowCoord][endColCoord];
						aBoard[endRowCoord][endColCoord] = tmp;
					}
				}
			}
		}
		if (!canMove)
		{
			cout << "Invalid given Coordinates!";
			cout << endl;
		}
	} while (!canMove);
}

void Game::switchTurns()
{
	if (playerTurn == 'W')
	{
		playerTurn = 'B';
	}
	else playerTurn = 'W';
}

bool Game::isGameOver()
{
	bool canMove(false);
	canMove = playBoard.AllowedMove(playerTurn);
	if (!canMove)
	{
		if (playBoard.isCheck(playerTurn))
		{
			switchTurns();
			cout << "CHECKMATE";
			getPlayerTurn();
			cout << ", WINS" << endl;
		}
		else
		{
			cout << "DRAW!" << endl;
		}
	}
	return !canMove;
}

void Game::Play()
{
	do
	{
		getNextMove(playBoard.aBoard);
		switchTurns();
	} while (!isGameOver());
	playBoard.printBoard();
}

