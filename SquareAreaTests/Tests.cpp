#include "gtest/gtest.h"
#include "../SquareAreaLib/Point.h"
#include "../SquareAreaLib/SquareArea.h"

TEST(PointConstructorTest, DefaultConstructor) {
    Point p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointConstructorTest, ConstructorWithParameters) {
    Point p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(PointMethodsTest, DistanceInLineSameX) {
    Point p1(1, 2);
    Point p2(1, 5);
    EXPECT_EQ(p1.distance_in_line(p2), 3);
}

TEST(PointMethodsTest, DistanceInLineSameY) {
    Point p1(2, 5);
    Point p2(6, 5);
    EXPECT_EQ(p1.distance_in_line(p2), 4);
}

TEST(PointMethodsTest, DistanceInLineNegativeCordinates) {
    Point p1(-12, -5);
    Point p2(-6, -5);
    EXPECT_EQ(p1.distance_in_line(p2), 6);
}

TEST(PointMethodsTest, DistanceInLineInvalid) {
    Point p1(1, 2);
    Point p2(3, 4);
    EXPECT_THROW(p1.distance_in_line(p2), std::invalid_argument);
}

TEST(PointMethodsTest, EqualityOperator) {
    Point p1(3, 4);
    Point p2(3, 4);
    Point p3(5, 6);
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointMethodsTest, OutputOperator) {
    Point p(3, 4);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "(3,4)");
}

TEST(SquareConstructorTest, DefaultConstructor) {
    Square square;
    EXPECT_EQ(square.getA(), Point(0, 0));
    EXPECT_EQ(square.getB(), Point(0, 0));
    EXPECT_EQ(square.getC(), Point(0, 0));
    EXPECT_EQ(square.getD(), Point(0, 0));
}

TEST(SquareConstructorTest, ConstructorWithTwoPoints) {
    Square square(Point(1, 1), Point(3, 3));
    EXPECT_EQ(square.getA(), Point(1, 1));
    EXPECT_EQ(square.getB(), Point(3, 1));
    EXPECT_EQ(square.getC(), Point(3, 3));
    EXPECT_EQ(square.getD(), Point(1, 3));
}

TEST(SquareConstructorTest, ConstructorWithBothCordsNegative) {
    Square square(Point(-3, -3), Point(-1, -1));
    EXPECT_EQ(square.getA(), Point(-3, -3));
    EXPECT_EQ(square.getB(), Point(-1, -3));
    EXPECT_EQ(square.getC(), Point(-1, -1));
    EXPECT_EQ(square.getD(), Point(-3, -1));
}

TEST(SquareConstructorTest, ConstructorWithOneCordNegative) {
    Square square(Point(-1, -1), Point(3, 3));
    EXPECT_EQ(square.getA(), Point(-1, -1));
    EXPECT_EQ(square.getB(), Point(3, -1));
    EXPECT_EQ(square.getC(), Point(3, 3));
    EXPECT_EQ(square.getD(), Point(-1, 3));
}

TEST(SquareConstructorTest, ConstructorWithFourPoints) {
    Square square(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3));
    EXPECT_EQ(square.getA(), Point(1, 1));
    EXPECT_EQ(square.getB(), Point(3, 1));
    EXPECT_EQ(square.getC(), Point(3, 3));
    EXPECT_EQ(square.getD(), Point(1, 3));
}

TEST(SquareConstructorTest, InvalidSquare) {
    Point A(0, 0);
    Point B(2, 0);
    Point C(2, 2);
    Point D(2, 1);
    EXPECT_THROW(Square square(A, B, C, D);, std::invalid_argument);
}

TEST(SquareConstructorTest, ConstructorSameParameters) {
    Point A(1, 1);
    Point B(1, 1);
    Point C(1, 1);
    Point D(1, 1);
    EXPECT_THROW(Square square(A, B, C, D);, std::invalid_argument);
}

TEST(SquareBasicMethodsTest, Area) {
    Square square(Point(0, 0), Point(2, 2));
    EXPECT_EQ(square.area(), 4);
}

TEST(SquareBasicMethodsTest, AreaNegativeCordinates) {
    Square square(Point(-3, -3), Point(-1, -1));
    EXPECT_EQ(square.area(), 4);
}

TEST(SquareBasicMethodsTest, Perimeter) {
    Square square(Point(1, 1), Point(3, 3));
    EXPECT_EQ(square.perimeter(), 8);
}

TEST(SquareBasicMethodsTest, PerimeterNegativeCordinates) {
    Square square(Point(-3, -3), Point(-1, -1));
    EXPECT_EQ(square.perimeter(), 8);
}

TEST(SquareBasicMethodsTest, Diagonal) {
    Square square(Point(0, 0), Point(2, 2));
    EXPECT_NEAR(square.diagonal(), 2.82843, 0.00001);
}

TEST(SquareBasicMethodsTest, DiagonalNegativeCordinates) {
    Square square(Point(-3, -3), Point(-1, -1));
    EXPECT_NEAR(square.diagonal(), 2.82843, 0.00001);
}

TEST(SquareBasicMethodsTest, Center) {
    Square square(Point(1, 1), Point(3, 3));
    EXPECT_EQ(square.center(), Point(2, 2));
}

TEST(SquareBasicMethodsTest, CenterNegativeCordinates) {
    Square square(Point(-3, -3), Point(-1, -1));
    EXPECT_EQ(square.center(), Point(-2, -2));
}

TEST(SquareBasicMethodsTest, CenterOddSides) {
    Square square(Point(0, 0), Point(3, 3));
    EXPECT_EQ(square.center(), Point(1, 1));
}

TEST(SquareOperatorTest, AdditionOperator) {
    Square square1(Point(0, 0), Point(2, 2));
    Square square2(Point(1, -3), Point(5, 1));
    Square result = square1 + square2;
    EXPECT_EQ(result.getA(), Point(1, 0));
    EXPECT_EQ(result.getB(), Point(2, 0));
    EXPECT_EQ(result.getC(), Point(2, 1));
    EXPECT_EQ(result.getD(), Point(1, 1));
}

TEST(SquareOperatorTest, AdditionOperatorCommonRectangle) {
    Square square1(Point(0, 0), Point(2, 2));
    Square square2(Point(1, -3), Point(7, 3));
    Square result = square1 + square2;
    EXPECT_EQ(result.getA(), Point(1, 0));
    EXPECT_EQ(result.getB(), Point(2, 0));
    EXPECT_EQ(result.getC(), Point(2, 1));
    EXPECT_EQ(result.getD(), Point(1, 1));
}

TEST(SquareOperatorTest, AdditionOperatorNoCommonArea) {
    Square square1(Point(0, 0), Point(2, 2));
    Square square2(Point(6, 6), Point(8, 8));
    Square result = square1 + square2;
    EXPECT_EQ(result.getA(), Point(0, 0));
    EXPECT_EQ(result.getB(), Point(0, 0));
    EXPECT_EQ(result.getC(), Point(0, 0));
    EXPECT_EQ(result.getD(), Point(0, 0));
}

TEST(SquareOperatorTest, AdditionOperatorNegativeCords) {
    Square square1(Point(-4, -4), Point(-1, -1));
    Square square2(Point(-5, -5), Point(-3, -3));
    Square result = square1 + square2;
    EXPECT_EQ(result.getA(), Point(-4, -4));
    EXPECT_EQ(result.getB(), Point(-3, -4));
    EXPECT_EQ(result.getC(), Point(-3, -3));
    EXPECT_EQ(result.getD(), Point(-4, -3));
}

TEST(SquareOperatorTest, AddAndAssignOperator) {
    Square square1(Point(0, 0), Point(2, 2));
    Square square2(Point(1, -3), Point(5, 1));
    square1 += square2;
    EXPECT_EQ(square1.getA(), Point(1, 0));
    EXPECT_EQ(square1.getB(), Point(2, 0));
    EXPECT_EQ(square1.getC(), Point(2, 1));
    EXPECT_EQ(square1.getD(), Point(1, 1));
}

TEST(SquareOperatorTest, MultiplicationOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(4, 4), Point(6, 6));
    Square result = square1 * square2;
    EXPECT_EQ(result.getA(), Point(1, 1));
    EXPECT_EQ(result.getB(), Point(6, 1));
    EXPECT_EQ(result.getC(), Point(6, 6));
    EXPECT_EQ(result.getD(), Point(1, 6));
}

TEST(SquareOperatorTest, MultiplicationOperatorMaxRectangle) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(4, 3), Point(7, 6));
    Square result = square1 * square2;
    EXPECT_EQ(result.getA(), Point(1, 1));
    EXPECT_EQ(result.getB(), Point(6, 1));
    EXPECT_EQ(result.getC(), Point(6, 6));
    EXPECT_EQ(result.getD(), Point(1, 6));
}

TEST(SquareOperatorTest, MultiplicationOperatorAreaInCommon) {
    Square square1(Point(1, 1), Point(6, 6));
    Square square2(Point(3, 2), Point(5, 4));
    Square result = square1 * square2;
    EXPECT_EQ(result.getA(), Point(1, 1));
    EXPECT_EQ(result.getB(), Point(6, 1));
    EXPECT_EQ(result.getC(), Point(6, 6));
    EXPECT_EQ(result.getD(), Point(1, 6));
}

TEST(SquareOperatorTest, MultiplicationOperatorNegativeCords) {
    Square square1(Point(-3, -3), Point(-1, -1));
    Square square2(Point(-6, -6), Point(-4, -4));
    Square result = square1 * square2;
    EXPECT_EQ(result.getA(), Point(-6, -6));
    EXPECT_EQ(result.getB(), Point(-1, -6));
    EXPECT_EQ(result.getC(), Point(-1, -1));
    EXPECT_EQ(result.getD(), Point(-6, -1));
}

TEST(SquareOperatorTest, MultiplyAndAssignOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(4, 4), Point(6, 6));
    square1 *= square2;
    EXPECT_EQ(square1.getA(), Point(1, 1));
    EXPECT_EQ(square1.getB(), Point(6, 1));
    EXPECT_EQ(square1.getC(), Point(6, 6));
    EXPECT_EQ(square1.getD(), Point(1, 6));
}

TEST(SquareComparisonTest, LessThanOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(4, 3), Point(7, 6));
    EXPECT_TRUE(square1 < square2);
    EXPECT_FALSE(square2 < square1);
}

TEST(SquareComparisonTest, LessThanOperatorNegative) {
    Square square1(Point(-3, -3), Point(-1, -1));
    Square square2(Point(-7, -6), Point(-4, -3));
    EXPECT_TRUE(square1 < square2);
    EXPECT_FALSE(square2 < square1);
}

TEST(SquareComparisonTest, GreaterThanOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(4, 3), Point(7, 6));
    EXPECT_TRUE(square2 > square1);
    EXPECT_FALSE(square1 > square2);
}

TEST(SquareComparisonTest, GreaterThanOperatorNegative) {
    Square square1(Point(-3, -3), Point(-1, -1));
    Square square2(Point(-7, -6), Point(-4, -3));
    EXPECT_TRUE(square2 > square1);
    EXPECT_FALSE(square1 > square2);
}

TEST(SquareComparisonTest, EqualityOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(1, 1), Point(3, 3));
    Square square3(Point(4, 4), Point(6, 6));
    EXPECT_TRUE(square1 == square2);
    EXPECT_FALSE(square1 == square3);
}

TEST(SquareComparisonTest, EqualityOperatorNegative) {
    Square square1(Point(-3, -3), Point(-1, -1));
    Square square2(Point(-3, -3), Point(-1, -1));
    Square square3(Point(-6, -6), Point(-4, -4));
    EXPECT_TRUE(square1 == square2);
    EXPECT_FALSE(square1 == square3);
}

TEST(SquareComparisonTest, InequalityOperator) {
    Square square1(Point(1, 1), Point(3, 3));
    Square square2(Point(1, 1), Point(3, 3));
    Square square3(Point(4, 4), Point(6, 6));
    EXPECT_TRUE(square1 != square3);
    EXPECT_FALSE(square1 != square2);
}

TEST(SquareComparisonTest, InequalityOperatorNegative) {
    Square square1(Point(-3, -3), Point(-1, -1));
    Square square2(Point(-3, -3), Point(-1, -1));
    Square square3(Point(-6, -6), Point(-4, -4));
    EXPECT_TRUE(square1 != square3);
    EXPECT_FALSE(square1 != square2);
}

TEST(SquareStreamTest, OutputOperator) {
    Square square(Point(1, 1), Point(3, 3));
    std::stringstream ss;
    ss << square;
    std::string expected = "Square: (1,1), (3,1), (3,3), (1,3), Area: 4\n";
    EXPECT_EQ(ss.str(), expected);
}

TEST(SquareStreamTest, OutputOperatorNegative) {
    Square square(Point(-3, -3), Point(-1, -1));
    std::stringstream ss;
    ss << square;
    std::string expected = "Square: (-3,-3), (-1,-3), (-1,-1), (-3,-1), Area: 4\n";
    EXPECT_EQ(ss.str(), expected);
}

TEST(SquareStreamTest, InputOperator) {
    Square square;
    std::stringstream ss("1 1 3 1 3 3 1 3");
    ss >> square;
    EXPECT_EQ(square.getA(), Point(1, 1));
    EXPECT_EQ(square.getB(), Point(3, 1));
    EXPECT_EQ(square.getC(), Point(3, 3));
    EXPECT_EQ(square.getD(), Point(1, 3));
}

TEST(SquareStreamTest, InputOperatorNegative) {
    Square square;
    std::stringstream ss("-3 -3 -1 -3 -1 -1 -3 -1");
    ss >> square;
    EXPECT_EQ(square.getA(), Point(-3, -3));
    EXPECT_EQ(square.getB(), Point(-1, -3));
    EXPECT_EQ(square.getC(), Point(-1, -1));
    EXPECT_EQ(square.getD(), Point(-3, -1));
}