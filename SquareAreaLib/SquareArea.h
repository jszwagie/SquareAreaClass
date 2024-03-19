#pragma once
#include <iostream>
#include <stdexcept>
#include "Point.h"

class Square
{
private:
	Point A;
	Point B;
	Point C;
	Point D;
	bool check_if_square(Point A, Point B, Point C, Point D) const noexcept;
	void init(Point A, Point B, Point C, Point D);
	int side() const noexcept;
public:
	Square();
	Square(Point A, Point C);
	Square(Point A, Point B, Point C, Point D);
	Square(Square const& s) = default;
	~Square() = default;
	Square& operator=(Square const& s) = default;
	int area() const noexcept;
	int perimeter() const noexcept;
	double diagonal() const noexcept;
	Point center() const noexcept;
};