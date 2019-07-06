#pragma once
#include"Vector.h"
#include <iostream>
#include "String.h"

using namespace std;

class Board;


class Piece
{
private:
	char color;
	virtual bool isSquareCorrect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]) = 0;
	//stRow - стартитращи координати на реда (Х,у)
	//stCol - стартиращо координати на колоната (х,У)
	//desRow - координати на дестинацията на реда  (Х,у)
	//desCol - координати на дестинацията на колоната (х,У)
	//aBoard - двумерен масив от фигури с размер 8х8
public:
	Piece(char color);
	~Piece();
	virtual char getPiece() const = 0;
	char getColor() const { return this->color; }
	bool isMoveCorect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);

};