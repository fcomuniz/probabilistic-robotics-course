//
// Created by francisco on 02/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H

#include <fstream>
#include "utils/configuration/DiscreteWorldConfigurationData.h"

namespace utils{
class DiscreteWorldFileParser {
public:
    DiscreteWorldFileParser();
    void parse(std::ifstream & confFile);
    DiscreteWorldConfigurationData getConfigurationData();
private:
    bool hasParsed;

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
