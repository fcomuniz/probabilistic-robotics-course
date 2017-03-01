//
// Created by francisco on 20/02/17.
//

#include "OmnidirectionalRobot_UnitTest.h"

using ::robot::OmnidirectionalRobot;

typedef ::testing::Types<int,double,float> MyTypes;
TYPED_TEST_CASE(OmnidirectionalRobot_UnitTest, MyTypes);

TYPED_TEST(OmnidirectionalRobot_UnitTest, initialization_test){

    OmnidirectionalRobot<TypeParam > robot;
    ASSERT_DOUBLE_EQ(robot.position.x, 0);
    ASSERT_DOUBLE_EQ(robot.position.y, 0);
}