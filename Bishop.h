#pragma once
#include "Pieces.h"


class Bishop : public Piece
{
private:
	virtual char getPiece() const { return 'B'; }
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);

public:
	Bishop(char color) : Piece(color) {}
	~Bishop() {};
};
bool Bishop::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	if ((desCol - stCol == desRow - stRow) || (desCol - stCol == stRow - desRow))
	{
		int disRow, disCol,r,c;
		if (desRow - stRow > 0)
		{
			disRow = 1;
		}
		else disCol = -1;

		if (desCol - stCol > 0)
		{
			disCol = 1;
		}
		else disCol = -1;

		for (r = stRow + disRow, c = stCol + disCol; r != desRow; r += desRow, c += desCol)
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

	