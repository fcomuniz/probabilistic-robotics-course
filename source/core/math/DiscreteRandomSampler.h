//
// Created by samcerq on 3/1/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETERANDOMSAMPLER_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETERANDOMSAMPLER_H


#include <representations/DiscreteDistribution.h>

class DiscreteRandomSampler {
public:
    DiscreteRandomSampler(representations::DiscreteDistribution);
    DiscreteRandomSampler(std::vector<representations::Position<int>>,std::vector<double>);

    representations::Position<int> getSample();
private:
    representations::DiscreteDistribution distribution;
};


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETERANDOMSAMPLER_H
