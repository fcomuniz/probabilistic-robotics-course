//
// Created by francisco on 17/02/17.
//

#include "GridWorld.h"

namespace world{

GridWorld::GridWorld(int rows, int cols, std::vector<sensor::DiscreteSensor> sensors, itandroids_lib::math::Vector2i robotPosition): sensors(sensors), rows(rows), cols(cols), robot(robotPosition), sampler(representations::DiscreteDistribution()){
    checkSensorsWithinBounds();

}

GridWorld::GridWorld(int rows, int cols, std::vector<sensor::DiscreteSensor> sensors, itandroids_lib::math::Vector2i robotPosition, representations::DiscreteDistribution distribution): sensors(sensors), rows(rows), cols(cols), robot(robotPosition),sampler(distribution){
    checkSensorsWithinBounds();

}


std::vector<sensor::DiscreteSensor> GridWorld::updateWorld(itandroids_lib::math::Vector2i robotCommand) {

    updateRobotPosition(robotCommand);
    updateSensors();
    return sensors;
}

void GridWorld::updateRobotPosition(itandroids_lib::math::Vector2i robotCommand) {
    auto nextValue = robot.position + robotCommand;
    auto randomValue = sampler.getSample();
    nextValue.x += randomValue.x;
    nextValue.y += randomValue.y;
    if(isInBounds(nextValue)){
        robot.position = nextValue;
    } else if(nextValue.x >= 0 && nextValue.x < cols ){
        robot.position.x = nextValue.x;
    } else if(nextValue.y >= 0 && nextValue.y < cols ) {
        robot.position.y = nextValue.y;

    }
}

void GridWorld::updateSensors() {
    for(auto & sensor: sensors){
        sensor.updateSensedPosition(robot);
    }
}

bool GridWorld::isInBounds(itandroids_lib::math::Vector2i valueToCheck) {
    bool value = true;
    value = value && (valueToCheck.x >= 0 && valueToCheck.x < cols);
    value = value && (valueToCheck.y >= 0 && valueToCheck.y < rows);
    return value;
}

void GridWorld::checkSensorsWithinBounds() {
    bool areWithinBounds = true;
    for(auto & sensor : sensors){
        areWithinBounds = areWithinBounds && isInBounds(sensor.position);
    }
    if(!areWithinBounds){
        throw std::runtime_error("The sensors aren't within the given bounds");
    }

}

itandroids_lib::math::Vector2<int> GridWorld::getGroundTruth(){
    return robot.position;
}

const int GridWorld::getRows() const {
    return rows;
}

const int GridWorld::getCols() const {
    return cols;
}
}