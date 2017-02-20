//
// Created by francisco on 17/02/17.
//

#include "GridWorld_UnitTest.h"
#include <gtest/gtest.h>

TEST(GridWorld_UnitTest, construction_test){

   world::GridWorld world(10,10, std::vector<sensor::Sensor<int>>());
   auto test = world.updateWorld(2);

}

