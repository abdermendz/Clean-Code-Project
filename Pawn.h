#pragma once
#include "Pieces.h"

class Pawn : public Piece
{
private:
	virtual char getPiece() const;
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);

public:
	Pawn(char color) : Piece(color) {}
	~Pawn() {};
};
char Pawn::getPiece() const
{
	return 'P';
}
bool Pawn::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	Piece* Dest = aBoard[desRow][desCol];
	if (Dest == 0)
	{
		if (stCol == desCol)
		{
			if (getColor() == 'W')
			{
				if (desRow == stRow + 1)
				{
					return true;
				}
			}
			else
			{
				if (desRow == stRow - 1)
				{
					return true;
				}
			}
		}
	}
	else
	{
		if ((stCol == desCol + 1) || (stCol == desCol - 1))
		{
			if (getColor() == 'W')
			{
				if (desRow == stRow + 1)
				{
					return true;
				}
			}
			else
			{
				if (desRow == stRow - 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}