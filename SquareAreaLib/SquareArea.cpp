#include "SquareArea.h"
#include "Point.h"
#include <cmath>
#include <algorithm>


bool Square::check_if_square(Point A, Point B, Point C, Point D) const noexcept
{
	bool result = false;
	if (A.getX() == D.getX() && A.getY() == B.getY() && C.getX() == B.getX() && C.getY() == D.getY())
		if (A.distance_in_line(B) == A.distance_in_line(D))
			result = true;
	return result;
		
}

int* Square::common_points(const Square& s) const noexcept
{
	int minX1 = std::min(A.getX(), B.getX());
	int maxX1 = std::max(A.getX(), B.getX());
	int minX2 = std::min(s.A.getX(), s.B.getX());
	int maxX2 = std::max(s.A.getX(), s.B.getX());
	int fMinX = std::max(minX1, minX2);
	int fMaxX = std::min(maxX1, maxX2);
	int minY1 = std::min(A.getY(), D.getY());
	int maxY1 = std::max(A.getY(), D.getY());
	int minY2 = std::min(s.A.getY(), s.D.getY());
	int maxY2 = std::max(s.A.getY(), s.D.getY());
	int fMinY = std::max(minY1, minY2);
	int fMaxY = std::min(maxY1, maxY2);
	int array[4] = { fMinX, fMaxX, fMinY, fMaxY };
	return array;
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

Square::Square() : A(Point(0, 0)), B(Point(0, 0)), C(Point(0, 0)), D(Point(0, 0)) {}

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

bool Square::operator<(Square const& s) const noexcept
{
	return area() < s.area();
}
bool Square::operator>(Square const& s) const noexcept
{
	return area() > s.area();
}
bool Square::operator==(Square const& s) const noexcept
{
	return (A == s.A && B == s.B && C == s.C && D == s.D);
}
bool Square::operator!=(Square const& s) const noexcept
{
	return !(*this == s);
}

void Square::operator+=(Square const& s) noexcept
{
	int* arr = common_points(s);
	int MinX = arr[0];
	int MaxX = arr[1];
	int MinY = arr[2];
	int MaxY = arr[3];
	Square Y;
	Square X;
	bool checker;
	while (MaxY != MinY)
	{
		checker = check_if_square(Point(MinX, MinY), Point(MaxX, MinY),
			Point(MaxX, MaxY), Point(MinX, MaxY));
		if (checker)
		{
			Y.init(Point(MinX, MinY), Point(MaxX, MinY),
				Point(MaxX, MaxY), Point(MinX, MaxY));
			break;
		}
		else
			MaxY--;
	}
	while (MaxX != MinX)
	{
		checker = check_if_square(Point(MinX, MinY), Point(MaxX, MinY),
			Point(MaxX, MaxY), Point(MinX, MaxY));
		if (checker)
		{
			X.init(Point(MinX, MinY), Point(MaxX, MinY),
				Point(MaxX, MaxY), Point(MinX, MaxY));
			break;
		}
		else
			MaxX--;
	}
	if (X.area() > Y.area())
		*this = X;
	else
		*this = Y;
}

std::ostream& operator<<(std::ostream& os, Square const& s)
{
	os << s.A << ", " << s.B << ", " << s.C << ", " << s.D;
	return os;
}

Square Square::operator+(Square const& s) const noexcept
{
	Square res(*this);
	res += s;
	return res;
}