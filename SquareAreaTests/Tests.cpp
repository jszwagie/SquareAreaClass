#include "gtest/gtest.h"
#include "../SquareAreaLib/Point.h"
#include "../SquareAreaLib/SquareArea.h"

TEST(PointTest, TestConstructorAndGetters) {
    Point p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(SquareTest, ConstructorDiagonals) {
    Point A(0, 0);
    Point C(2, 2);
    Square square(A, C);
    EXPECT_EQ(0, 0);
}

TEST(SquareTest, ConstructorPoints) {
    Point A(0, 0);
    Point B(0, 2);
    Point C(2, 2);
    Point D(2, 0);
    Square square(A, B, C, D);
    EXPECT_EQ(0, 0);
}

TEST(SquareTest, ConstructorDefault) {
    Square square();
    EXPECT_EQ(0, 0);
}