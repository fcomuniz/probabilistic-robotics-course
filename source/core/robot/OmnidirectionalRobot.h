//
// Created by francisco on 20/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_OMNIDIRECTIONALROBOT_H
#define ROBOTICS_PROBABILISTICS_COURSE_OMNIDIRECTIONALROBOT_H

#include "robot/Robot.h"
#include "representations/Position.h"
using representations::Position;
namespace robot{
template<typename T>
class OmnidirectionalRobot : public Robot<Position<T>>{
    using Robot<Position<T>>::Robot;

};

}


#endif //ROBOTICS_PROBABILISTICS_COURSE_OMNIDIRECTIONALROBOT_H
