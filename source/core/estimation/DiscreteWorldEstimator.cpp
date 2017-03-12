//
// Created by francisco on 12/03/17.
//

#include "DiscreteWorldEstimator.h"

namespace estimation{
void DiscreteWorldEstimator::estimate(world::GridWorld &world, Sensors & sensors) {
    worldEstimate.estimateMatrix.resize(world.getRows(), world.getCols());
    generateProbabilityMatrix(world, sensors);
    generateRobotPositionEstimate();
}

Estimate &DiscreteWorldEstimator::getWorldEstimate(){
    return worldEstimate;
}

void DiscreteWorldEstimator::generateProbabilityMatrix(world::GridWorld &world, Sensors &sensors) {
//Generate the probability matrix in the world Estimate
}

void DiscreteWorldEstimator::generateRobotPositionEstimate() {
    // Generate the robot Position Estimate from the probabilty matrix;
}
}
