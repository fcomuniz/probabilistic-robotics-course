//
// Created by francisco on 01/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H

#include "representations/Position.h"
#include "sensor/DiscreteSensor.h"
#include "eigen3/Eigen/Eigen"

using Sensors = std::vector<sensor::DiscreteSensor>;

struct DiscreteWorldData {
    DiscreteWorldData(representations::Position<int> robotRealPosition, representations::Position<int> robotEstimate, Eigen::MatrixXd fmp, Sensors sensors);

    representations::Position <int> robotRealPosition;
    representations::Position<int> robotEstimate;
    Eigen::MatrixXd fmp;
    Sensors sensors;

};


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDDATA_H
