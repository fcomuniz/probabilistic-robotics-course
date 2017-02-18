//
// Created by francisco on 18/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSORPOSITION_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSORPOSITION_H

#include "eigen3/Eigen/Eigen"


namespace sensor{

template <typename T>
class SensorPosition {

};
template <>
class SensorPosition<int> : public Eigen::Vector2i {

};

}

#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSORPOSITION_H
