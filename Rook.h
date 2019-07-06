#pragma once
#include "Pieces.h"


class Rook : public Piece
{
private:
	virtual char getPiece() const { return 'R'; }
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);
public:
	Rook(char color) : Piece(color) {}
	~Rook() {}
};
bool Rook::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
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
	else if (desCol == stRow)
	{
		int disRow;
		if (desRow - stRow > 0)
		{
			disRow = 1;
		}
		else disRow = -1;
		for (int i = stRow + disRow; i != desRow; i += disRow)
		{
			if (aBoard[i][stCol] != 0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
