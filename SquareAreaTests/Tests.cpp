#include "gtest/gtest.h"
#include "../SquareAreaLib/Point.h"

TEST(PointTest, TestConstructorAndGetters) {
    Point p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}