#pragma once

class Point
{
private:
	int x = 0;
	int y = 0;
public:
	Point(int x, int y);
	Point(Point const& s) = default;
	~Point() = default;
	Point& operator=(Point const& s) = default;
	int getX() const;
	int getY() const;
};