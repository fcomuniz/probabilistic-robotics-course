//
// Created by francisco on 20/02/17.
//

#include "DiscreteSensor.h"

namespace sensor{

void DiscreteSensor::updateSensedPosition(const robot::OmnidirectionalRobot<int> & robot) {
    sensedPosition.x = robot.position.x - position.x;
    sensedPosition.y = robot.position.y - position.y;
    addNoiseToSensedPosition();
}

DiscreteSensor::DiscreteSensor(representations::Position<int> sensorPosition) : position(sensorPosition){

}

void DiscreteSensor::addNoiseToSensedPosition() {

}
}