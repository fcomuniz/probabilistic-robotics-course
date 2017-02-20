//
// Created by francisco on 20/02/17.
//

#include "DifferentialRobot_UnitTest.h"

using ::robot::DifferentialRobot;

typedef ::testing::Types<int,double,float> MyTypes;
TYPED_TEST_CASE(DifferentialRobot_UnitTest, MyTypes);

TYPED_TEST(DifferentialRobot_UnitTest, initialization_test){

    DifferentialRobot robot;
    ASSERT_DOUBLE_EQ(robot.position.translation.x, 0);
    ASSERT_DOUBLE_EQ(robot.position.translation.y, 0);
}
