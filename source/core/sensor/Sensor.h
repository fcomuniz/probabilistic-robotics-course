//
// Created by francisco on 18/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H

#include "eigen3/Eigen/StdVector"
#include "representations/Position.h"
namespace sensor{
using representations::Position;

template<typename T>
class Sensor {
public:
    Sensor(Position<T> position): position(position) {

    }

    void updateSensedPosition(Position<T> & position){

    }



    Position<T> position;


};

}


#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSOR_H
