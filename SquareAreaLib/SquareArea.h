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
	int* common_points(const Square& s) const noexcept;
	int* max_points(const Square& s) const noexcept;
	Square get_square(int *arr) const noexcept;

public:
	Square();
	Square(Point A, Point C);
	Square(Point A, Point B, Point C, Point D);
	Square(Square const& s) = default;
	~Square() = default;
	Square& operator=(Square const& s) = default;

	Point getA() const noexcept;
	Point getB() const noexcept;
	Point getC() const noexcept;
	Point getD() const noexcept;

	int area() const noexcept;
	int perimeter() const noexcept;
	double diagonal() const noexcept;
	Point center() const noexcept;

	Square operator+(Square const& s) const noexcept;
	Square operator*(Square const& s) const noexcept;
	void operator+=(Square const& s) noexcept;
	void operator*=(Square const& s) noexcept;
	bool operator<(Square const& s) const noexcept;
	bool operator>(Square const& s) const noexcept;
	bool operator==(Square const& s) const noexcept;
	bool operator!=(Square const& s) const noexcept;

	friend std::ostream& operator<<(std::ostream& os, Square const& s);
};