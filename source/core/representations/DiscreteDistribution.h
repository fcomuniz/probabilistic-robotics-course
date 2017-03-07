//
// Created by samcerq on 3/1/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETENOISE_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETENOISE_H

#include "representations/Position.h"
#include <vector>
#include <utility>

namespace representations{
    using DiscreteDistribution =  std::vector<std::pair<representations::Position<int>,double>>;
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETENOISE_H
