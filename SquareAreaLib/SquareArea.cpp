#include "SquareArea.h"
#include "Point.h"

bool Square::check_if_square() const noexcept
{
	return true;
}


void Square::init(Point A, Point B, Point C, Point D)
{
	if (!check_if_square())
		throw std::invalid_argument("Inalid points, not a square");
	else
	{
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
}

Square::Square() : A(Point()), B(Point()), C(Point()), D(Point()) {}

Square::Square(Point A, Point C)
{
	Point B(C.getX(), A.getY());
	Point D(A.getX(), C.getY());
	init(A, B, C, D);
}

Square::Square(Point A, Point B, Point C, Point D)
{
	init(A, B, C, D);
}