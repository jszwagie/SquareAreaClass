#pragma once
#include <iostream>

class Point
{
private:
	int x = 0;
	int y = 0;

public:
	Point();
	Point(int x, int y);
	Point(Point const& s) = default;
	~Point() = default;
	Point& operator=(Point const& s) = default;

	int getX() const;
	int getY() const;
	int distance_in_line(const Point& other) const;

	bool operator==(Point const& p) const noexcept;
	friend std::ostream& operator<< (std::ostream& os, Point const& p);
};