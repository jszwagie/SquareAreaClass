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
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    EXPECT_EQ(0, 0);
}

TEST(SquareTest, ConstructorDefault) {
    Square square();
    EXPECT_EQ(0, 0);
}

TEST(SquareTest, InvalidSquare1) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(2, 1);
    EXPECT_THROW(Square square(A, B, C, D);, std::invalid_argument);
}

TEST(SquareTest, Area) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    EXPECT_EQ(square.area(), 4);
}

TEST(SquareTest, Area2) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    EXPECT_EQ(square.area(), 4);
}

TEST(SquareTest, Perimeter) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    EXPECT_EQ(square.perimeter(), 8);
}

TEST(SquareTest, Diagonal) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    EXPECT_NEAR(square.diagonal(), 2.82843, 0.00001);
}

TEST(SquareTest, Center) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(0, 2);
    Square square(A, B, C, D);
    Point center = square.center();
    EXPECT_EQ(center.getX(), 1);
    EXPECT_EQ(center.getY(), 1);
}