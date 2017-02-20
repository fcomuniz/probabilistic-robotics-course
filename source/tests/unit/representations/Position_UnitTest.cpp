//
// Created by francisco on 20/02/17.
//

#include "Position_UnitTest.h"
#include <gtest/gtest.h>
using ::representations::Position;


TEST(Position_UnitTest, creation_test){
    Position<int> testingPosition;
    testingPosition.x() = 0;
    testingPosition.y() = 1;
    ASSERT_DOUBLE_EQ(testingPosition.x(), 0);
    ASSERT_DOUBLE_EQ(testingPosition.y(), 1);
   // testingPosition = testingPosition + testingPosition;

}