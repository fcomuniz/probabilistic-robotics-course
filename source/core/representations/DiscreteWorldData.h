//
// Created by francisco on 01/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H

#include "representations/Position.h"
#include "eigen3/Eigen/Eigen"

struct DiscreteWorldData {
    DiscreteWorldData(representations::Position<int> robotRealPosition, representations::Position<int> robotEstimate, Eigen::MatrixXd fmp);

    representations::Position <int> robotRealPosition;
    representations::Position<int> robotEstimate;
    Eigen::MatrixXd fmp;
};


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H
