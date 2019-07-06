#pragma once
#include<iostream>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"


class Board
{
public:
	Piece* aBoard[8][8];
	Board();
	~Board();
	bool isCheck(char color);
	bool AllowedMove(char color);
	void printBoard();
};

Board::Board()
{
	for (size_t row = 0; row < 8; ++row)
	{
		for (size_t col = 0; col < 8; ++col)
		{
			aBoard[row][col] = 0;
		}
	}

	for (int col = 0; col < 8; col++)
	{
		aBoard[6][col] = new Pawn('B');
	}
	aBoard[7][0] = new Rook('B');
	aBoard[7][1] = new Knight('B');
	aBoard[7][2] = new Bishop('B');
	aBoard[7][3] = new King('B');
	aBoard[7][4] = new Queen('B');
	aBoard[7][5] = new Bishop('B');
	aBoard[7][6] = new Knight('B');
	aBoard[7][7] = new Rook('B');

	for (int col = 0; col < 8; col++)
	{
		aBoard[1][col] = new Pawn('W');
	}
	aBoard[0][0] = new Rook('W');
	aBoard[0][1] = new Knight('W');
	aBoard[0][2] = new Bishop('W');
	aBoard[0][3] = new King('W');
	aBoard[0][4] = new Queen('W');
	aBoard[0][5] = new Bishop('W');
	aBoard[0][6] = new Knight('W');
	aBoard[0][7] = new Rook('W');
}

Board ::~Board()
{
	for (size_t row = 0; row < 8; ++row)
	{
		for (size_t col = 0; col < 8; ++col)
		{
			delete aBoard[row][col];
			aBoard[row][col] = 0;
		}
	}
}

bool Board::isCheck(char color)
{
	int locateKingRow, locateKingCol;

	for (size_t row = 0; row < 8; row++)
	{
		for (size_t col = 0; col < 8; col++)
		{
			if (aBoard[row][col] != 0)
			{
				if (aBoard[row][col]->getColor() == color)
				{
					if (aBoard[row][col]->getPiece() == 'K')
					{
						locateKingRow = row;
						locateKingCol = col;
					}
				}
			}
		}
	}

	for (size_t row = 0; row < 8; row++)
	{
		for (size_t col = 0; col < 8; col++)
		{
			if (aBoard[row][col] != 0)
			{
				if (!(aBoard[row][col]->getColor() == color))
				{
					if (aBoard[row][col]->isMoveCorect(row, col, locateKingRow, locateKingCol, aBoard))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void Board::printBoard()
{
	const size_t squareWidth = 4;
	const size_t squareHeight = 3;

	for (size_t row = 0; row < 8 * squareHeight; row++)
	{
		size_t squareRows = row / squareHeight;

		if (row % 3 == 1)
		{
			cout << "|" << (char)('1' + 7 - squareRows) << "|";
		}
		else cout << "|||";

		for (int col = 0; col < 8 * squareWidth; col++)
		{
			size_t squareCols = col / squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && aBoard[7 - squareRows][squareCols] != 0)
			{
				if ((col % 4) == 1)
				{
					cout <<aBoard[7 - squareRows][squareCols]->getColor();                         
				}
				else
				{
					cout <<aBoard[7 - squareRows][squareCols]->getPiece();
				}
			}
			else
			{
				if ((squareCols + squareRows) % 2 == 1)
				{
					cout << '#';
				}
				else cout << ' ';
			}
		}
		cout << endl;
	}
	for (int rows = 0; rows < squareHeight; rows++)
	{
		if (rows % 3 == 1)
		{
			cout << "|||";
			for (int cols = 0; cols < 8 * squareWidth; cols++)
			{
				int squareCols = cols / squareWidth;
				if ((cols % 4) == 1)
				{
					cout << (squareCols + 1);
				}
				else cout << '|';

			}
			cout << endl;
		}
		else
		{
			for (int col = 1; col < 9 * squareWidth; col++)
			{
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool Board::AllowedMove(char color)
{
	for (size_t row = 0; row < 8; row++)
	{
		for (size_t col = 0; col < 8; col++)
		{
			if (aBoard[row][col] != 0)
			{
				if (aBoard[row][col]->getColor() == color)
				{
					for (size_t availableRow = 0; availableRow < 8; availableRow++)
					{
						for (size_t availableCol = 0; availableCol < 8; availableCol++)
						{
							if (aBoard[row][col]->isMoveCorect(row, col, availableRow, availableCol, aBoard))
							{
								Piece* tmp = aBoard[availableRow][availableCol];
								aBoard[availableRow][availableCol] = aBoard[row][col];
								aBoard[row][col] = 0;
								bool canMove = !isCheck(color);

								aBoard[row][col] = aBoard[availableRow][availableCol];
								aBoard[availableRow][availableCol] = tmp;

								if (canMove == true)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}




