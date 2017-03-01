//
// Created by francisco on 20/02/17.
//

#include "DifferentialRobot_UnitTest.h"
#include "math/Pose2D.h"

using ::robot::DifferentialRobot;
using itandroids_lib::math::Pose2D;

typedef ::testing::Types<int,double,float> MyTypes;
TYPED_TEST_CASE(DifferentialRobot_UnitTest, MyTypes);

TEST(DifferentialRobot_UnitTest, initialization_test){

    DifferentialRobot robot;
    ASSERT_DOUBLE_EQ(robot.position.translation.x, 0);
    ASSERT_DOUBLE_EQ(robot.position.translation.y, 0);
}
