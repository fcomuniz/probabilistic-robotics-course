//
// Created by francisco on 17/02/17.
//

#include "GridWorld_UnitTest.h"
#include "sensor/DiscreteSensor.h"
#include <gtest/gtest.h>


TEST(GridWorld_UnitTest, construction_test){

   std::vector<sensor::DiscreteSensor> sensors;
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(4,1)));
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(3,2)));
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(4,5)));
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(2,8)));
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(1,0)));

   auto robotInitialPosition = itandroids_lib::math::Vector2<int>(5,5);
   world::GridWorld world(10,10, sensors, robotInitialPosition);
   auto updated_sensors = world.updateWorld(itandroids_lib::math::Vector2<int>(0,0));
   for(auto & sensor : updated_sensors){
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.x,robotInitialPosition.x- sensor.position.x );
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.y,robotInitialPosition.y- sensor.position.y );
   }
   updated_sensors.clear();
   updated_sensors = world.updateWorld(itandroids_lib::math::Vector2<int>(1,0));

   for(auto & sensor : updated_sensors){
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.x,robotInitialPosition.x- sensor.position.x + 1 );
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.y,robotInitialPosition.y- sensor.position.y );
   }
}


TEST(GridWorld_UnitTest, moveRobotOnEdges){
   std::vector<sensor::DiscreteSensor> sensors;
   sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(0,0)));

   auto robotInitialPosition = itandroids_lib::math::Vector2<int>(0,0);
   world::GridWorld world(10,10, sensors, robotInitialPosition);
   auto updated_sensors = world.updateWorld(itandroids_lib::math::Vector2<int>(1,0));
   for(auto & sensor : updated_sensors){
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.x,robotInitialPosition.x- sensor.position.x +1);
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.y,robotInitialPosition.y- sensor.position.y );
   }
    updated_sensors.clear();
   updated_sensors = world.updateWorld(itandroids_lib::math::Vector2<int>(0,1));
   for(auto & sensor : updated_sensors){
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.x,robotInitialPosition.x- sensor.position.x +1);
      ASSERT_DOUBLE_EQ(sensor.sensedPosition.y,robotInitialPosition.y- sensor.position.y + 1 );
   }
}

