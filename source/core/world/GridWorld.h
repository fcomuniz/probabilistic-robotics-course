//
// Created by francisco on 17/02/17.
//

#ifndef PROJECT_GRIDWORLD_H
#define PROJECT_GRIDWORLD_H


#include <math/DiscreteRandomSampler.h>
#include "world/World.h"
#include "sensor/DiscreteSensor.h"
#include "robot/OmnidirectionalRobot.h"
#include "math/Vector2.h"
#include <representations/DiscreteDistribution.h>

namespace world{

//class GridWorld :public World<int>{
class GridWorld{

public:
    GridWorld(int rows, int cols, std::vector<sensor::DiscreteSensor> sensors, itandroids_lib::math::Vector2i initialRobotPosition);
    GridWorld(int rows, int cols, std::vector<sensor::DiscreteSensor> sensors, itandroids_lib::math::Vector2i initialRobotPosition, representations::DiscreteDistribution distribution);

    std::vector<sensor::DiscreteSensor> updateWorld(itandroids_lib::math::Vector2i robotCommand);

    const int getRows() const;

    const int getCols() const;

    itandroids_lib::math::Vector2<int> getGroundTruth();
private:
    void checkSensorsWithinBounds();
    bool isInBounds(itandroids_lib::math::Vector2i vectorToCheck);
    void updateRobotPosition(itandroids_lib::math::Vector2i robotCommand);
    void updateSensors();
    std::vector<sensor::DiscreteSensor> sensors;
    robot::OmnidirectionalRobot<int> robot;
    const int rows;
    const int cols;
    DiscreteRandomSampler sampler;
};
}


#endif //PROJECT_GRIDWORLD_H
