#include "SquareArea.h"
#include "Point.h"
#include <cmath>


bool Square::check_if_square(Point A, Point B, Point C, Point D) const noexcept
{
	bool result = false;
	if (A.getX() == D.getX() && A.getY() == B.getY() && C.getX() == B.getX() && C.getY() == D.getY())
		if (A.distance_in_line(B) == A.distance_in_line(D))
			result = true;
	return result;
		
}


void Square::init(Point A, Point B, Point C, Point D)
{
	if (!check_if_square(A, B, C, D))
		throw std::invalid_argument("Inalid points, not a square");
	else
	{
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
}

int Square::side() const noexcept
{
	return A.distance_in_line(B);
}

Square::Square() : A(Point(0, 0)), B(Point(1, 0)), C(Point(1, 1)), D(Point(0, 1)) {}

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

int Square::area() const noexcept
{
	int a = side();
	return a * a;
}

int Square::perimeter() const noexcept
{
	return side() * 4;
}

double Square::diagonal() const noexcept
{
	return sqrt(2) * side();
}

Point Square::center() const noexcept
{
	return Point((A.getX() + B.getX()) / 2, (A.getY() + D.getY()) / 2);
}