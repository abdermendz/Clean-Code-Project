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
	//stRow - ����������� ���������� �� ���� (�,�)
	//stCol - ���������� ���������� �� �������� (�,�)
	//desRow - ���������� �� ������������ �� ����  (�,�)
	//desCol - ���������� �� ������������ �� �������� (�,�)
	//aBoard - �������� ����� �� ������ � ������ 8�8
public:
	Piece(char color);
	~Piece();
	virtual char getPiece() const = 0;
	char getColor() const { return this->color; }
	bool isMoveCorect(size_t stRow, size_t stCol, size_t desRow, size_t desCol, Piece* aBoard[8][8]);

};