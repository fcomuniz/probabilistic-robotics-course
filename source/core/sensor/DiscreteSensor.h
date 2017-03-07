//
// Created by francisco on 20/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H

#include <representations/DiscreteDistribution.h>
#include <math/DiscreteRandomSampler.h>
#include "representations/Position.h"
#include "robot/OmnidirectionalRobot.h"
namespace sensor{

class DiscreteSensor {
public:
    DiscreteSensor(representations::Position<int> sensorPosition);
    DiscreteSensor(representations::Position<int> sensorPosition, representations::DiscreteDistribution distribution);
    representations::Position<int> sensedPosition;
    representations::Position<int> position;
    void updateSensedPosition(const robot::OmnidirectionalRobot<int> & robot);
private:
    void addNoiseToSensedPosition();
    DiscreteRandomSampler sampler;

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H
