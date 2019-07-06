#pragma once
#include "Pieces.h"


class Knight : public Piece
{
private:
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);
	virtual char getPiece() const
	{
		return 'N';
	}
public:
	Knight(char color) : Piece(color) {}
	~Knight() {};

};
bool Knight::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	if ((stCol == desCol - 1) || (stCol == desCol + 1))
	{
		if ((stRow == desRow - 2) || (stRow == desRow + 2))
		{
			return true;
		}
	}
	if ((stCol == desCol + 2) || (stCol == desCol - 2))
	{
		if ((stRow == desRow + 1) || (stRow == desCol - 1))
		{
			return true;
		}
	}
	return false;
}