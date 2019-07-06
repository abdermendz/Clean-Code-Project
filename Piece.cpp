#include "stdafx.h"
#include "Pieces.h"


bool Piece::isMoveCorect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8])
{
	Piece* Dest = aBoard[desRow][desCol];
	if ((Dest == 0) || (color != Dest->getColor()))            
	{
		return isSquareCorrect(stRow, stCol, desRow, desCol, aBoard);
	}
	 return false;
}
Piece::Piece(char color)
{
	this->color = color;
}
Piece::~Piece() {};
