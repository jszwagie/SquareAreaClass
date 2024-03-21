#include <iostream>
#include "../SquareAreaLib/SquareArea.h"

int main()
{
    Square square1(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Square square2(Point(1, -3), Point(7, -3), Point(7, 3), Point(1, 3));
    square2 += square1;
    std::cout << square2 << std::endl;
    Square s3;
    s3 = square1 + square2;
    std::cout << s3 << std::endl;
}