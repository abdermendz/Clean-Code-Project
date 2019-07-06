#pragma once
#include "Pieces.h"


class Queen : public Piece
{
private:
	virtual char getPiece() const { return 'Q'; }
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);
public:
	Queen(char color) : Piece(color) {}
	~Queen() {}
};
bool Queen::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	if (stRow == desRow)
	{
		int disCol;
		if (desCol - stCol > 0)
		{
			disCol = 1;
		}
		else disCol = -1;

		for (int i = stCol + disCol; i != desCol; i += disCol)
		{
			if (aBoard[stRow][i] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (desCol == stCol)
	{
		int disRow;
		if (desRow - stRow > 0)
		{
			disRow = 1;
		}
		else disRow = -1;

		for(int i = stRow + disRow; i != desRow; i+= disRow)
		{
			if (aBoard[i][stCol] != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if ((desCol = stCol == desRow - stRow) || (desCol - stCol == stRow - desRow))
	{
		int disRow, disCol, r, c;
		if (desRow - stRow > 0)
		{
			disRow = 1;
		}
		else disRow = -1;

		if (desCol - stCol > 0)
		{
			disCol = 1;
		}
		else disCol = -1;

		for (r = stRow - disRow, c = stCol + disCol; r != desRow; r += disRow, c += disCol)
		{
			if (aBoard[r][c] != 0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


