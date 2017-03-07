//
// Created by francisco on 20/02/17.
//

#include "DiscreteSensor.h"

namespace sensor{

void DiscreteSensor::updateSensedPosition(const robot::OmnidirectionalRobot<int> & robot){
    sensedPosition.x = robot.position.x - position.x;
    sensedPosition.y = robot.position.y - position.y;
    auto randomSample = sampler.getSample();
    sensedPosition.x += randomSample.x;
    sensedPosition.y += randomSample.y;
}

DiscreteSensor::DiscreteSensor(representations::Position<int> sensorPosition) : position(sensorPosition), sampler(representations::DiscreteDistribution()) {

}
DiscreteSensor::DiscreteSensor(representations::Position<int> sensorPosition, representations::DiscreteDistribution distribution) : position(sensorPosition), sampler(distribution){

}

void DiscreteSensor::addNoiseToSensedPosition() {

}
}