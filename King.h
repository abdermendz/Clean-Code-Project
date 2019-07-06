#pragma once
#include"Pieces.h"


class King : public Piece
{
private:
	bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);
	virtual char getPiece() const { return 'K'; }
public:
	King(char color) : Piece(color) {}
	~King() {}
};
bool King::isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	int saveRow = desRow - stRow;
	int saveCol = desCol - stCol;
	if ((saveRow >= -1) && (saveRow <= 1) && (saveCol >= -1) && (saveCol <= 1))
	{
		return true;
	}
	return false;
}