//
// Created by francisco on 02/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H

#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "utils/configuration/DiscreteWorldConfigurationData.h"

using boost::property_tree::ptree;
namespace utils{
class DiscreteWorldFileParser {
public:
    DiscreteWorldFileParser();
    void parse(std::ifstream & confFile);
    void parse(ptree & tree);
    DiscreteWorldConfigurationData getConfigurationData();
private:
    bool hasParsed;

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
