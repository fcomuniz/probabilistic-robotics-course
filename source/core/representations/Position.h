//
// Created by francisco on 20/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_ROBOTPOSITION_H
#define ROBOTICS_PROBABILISTICS_COURSE_ROBOTPOSITION_H

#include "eigen3/Eigen/Eigen"

namespace representations{

template<typename T>
class Position {

};

template<>
class Position<int> : public Eigen::Vector2i{

};
}



#endif //ROBOTICS_PROBABILISTICS_COURSE_ROBOTPOSITION_H
