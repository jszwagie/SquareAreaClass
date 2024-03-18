#pragma once
#include <iostream>
#include <stdexcept>
#include "Point.h"

class Square
{
private:
	int x1 = 0;
	int y1 = 0;
public:
	Square(int x = 0, int y = 0);
	Square(Square const& s) = default;
	~Square() = default;
	Square& operator=(Square const& s) = default;
};