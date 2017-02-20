//
// Created by francisco on 18/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H

#include <robot/OmnidirectionalRobot.h>
#include "eigen3/Eigen/StdVector"
#include "representations/Position.h"
#include "sensor/SensorData.h"
#include "robot/Robot.h"
namespace sensor{
using representations::Position;

template<typename T>
class Sensor {
public:
    Sensor(Position<T> position): position(position) {

    }

    template<typename V>
    void updateSensorData(const robot::Robot<V> & robot){

    }



    Position<T> position;



};

}


#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
