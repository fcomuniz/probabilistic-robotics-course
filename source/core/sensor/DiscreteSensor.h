//
// Created by francisco on 20/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H

#include "representations/Position.h"
#include "robot/OmnidirectionalRobot.h"
namespace sensor{

class DiscreteSensor {
public:
    DiscreteSensor(representations::Position<int> sensorPosition);
    representations::Position<int> sensedPosition;
    representations::Position<int> position;
    void updateSensedPosition(const robot::OmnidirectionalRobot<int> & robot);
private:
    void addNoiseToSensedPosition();

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETESENSOR_H
