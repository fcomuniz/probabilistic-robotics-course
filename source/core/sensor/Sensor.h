//
// Created by francisco on 18/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H

#include "eigen3/Eigen/StdVector"
#include "SensorPosition.h"
namespace sensor{

template<typename T>
class Sensor {
public:
    Sensor(SensorPosition<T> position): position(position) {

    }
    SensorPosition<T> position;

};

}


#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
