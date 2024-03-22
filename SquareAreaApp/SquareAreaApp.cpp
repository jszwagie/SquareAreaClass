#include <iostream>
#include "../SquareAreaLib/SquareArea.h"

int main()
{
    Square square1;
    Square square2;
    Square square3;
    std::cout << "Enter first square paramethers in order: Xa, Ya, Xb, Yb, Xc, Yc, Xd, Yd" << '\n';
    std::cin >> square1;
    std::cout << "Enter second square paramethers in simillar order:" << '\n';
    std::cin >> square2;
    std::cout << "First square:" << '\n';
    std::cout << square1 << std::endl;
    std::cout << "Second square:" << '\n';
    std::cout << square2 << std::endl;
    square3 = square1 + square2;
    std::cout << " '+' of squares:" << '\n';
    std::cout << square3 << std::endl;
    square3 = square1 * square2;
    std::cout << " '*' of squares:" << '\n';
    std::cout << square3 << std::endl;
}