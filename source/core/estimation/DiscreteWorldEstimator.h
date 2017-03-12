//
// Created by francisco on 12/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDESTIMATOR_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDESTIMATOR_H

#include <world/GridWorld.h>
#include <sensor/DiscreteSensor.h>

using Sensors = std::vector<sensor::DiscreteSensor>;
namespace estimation{

struct Estimate {
    representations::Position<int> robotPosition;
    Eigen::MatrixXd estimateMatrix;
};

class DiscreteWorldEstimator {

public:
    void estimate(world::GridWorld & world, Sensors sensors);
    Estimate &getWorldEstimate();

private:
    Estimate worldEstimate;
};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDESTIMATOR_H
