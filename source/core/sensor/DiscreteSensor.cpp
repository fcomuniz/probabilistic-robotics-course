//
// Created by francisco on 20/02/17.
//

#include "DiscreteSensor.h"

namespace sensor{

void DiscreteSensor::updateSensedPosition(const robot::OmnidirectionalRobot<int> & robot) {
    sensedPosition = robot.position - position;
    addNoiseToSensedPosition();
}

DiscreteSensor::DiscreteSensor(representations::Position<int> sensorPosition) : position(sensorPosition){

}

void DiscreteSensor::addNoiseToSensedPosition() {

}
}