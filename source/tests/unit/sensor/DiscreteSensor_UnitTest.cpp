//
// Created by francisco on 20/02/17.
//

#include "DiscreteSensor_UnitTest.h"
#include "robot/OmnidirectionalRobot.h"

TEST(DiscreteSensor_UnitTest, construting_a_sensor){
    robot::OmnidirectionalRobot<int> robot;

    sensor::DiscreteSensor sensor(itandroids_lib::math::Vector2<int> (2,1));
    sensor.updateSensedPosition(robot);
    ASSERT_DOUBLE_EQ(sensor.sensedPosition.x, 0);
    ASSERT_DOUBLE_EQ(sensor.sensedPosition.y, 0);
    robot.position.x = 1;
    robot.position.y = 1;
    sensor.updateSensedPosition(robot);
    ASSERT_DOUBLE_EQ(sensor.sensedPosition.x, 1);
    ASSERT_DOUBLE_EQ(sensor.sensedPosition.y, 1);
}
