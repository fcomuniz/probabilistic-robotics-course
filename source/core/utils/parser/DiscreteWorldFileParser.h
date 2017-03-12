//
// Created by francisco on 02/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H

#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <memory>
#include <boost/property_tree/json_parser.hpp>
#include "utils/configuration/DiscreteWorldConfigurationData.h"
#include "representations/DiscreteTrajectory.h"
#include "sensor/DiscreteSensor.h"

namespace applications{
    class DiscreteWorld_main;
}


using boost::property_tree::ptree;
using Sensors = std::vector<sensor::DiscreteSensor>;
namespace utils{
class DiscreteWorldFileParser {
public:
    DiscreteWorldFileParser();
    void parse(std::ifstream & confFile);
    void parse(ptree & tree);
    DiscreteWorldConfigurationData getConfigurationData();
private:
    std::shared_ptr<DiscreteWorldConfigurationData> data;
    void parseWorldTree(ptree & tree);
    representations::Position<int> generateInitialRobotPosition(ptree & trajectoryTree
    );
    representations::DiscreteTrajectory generateTrajectory(ptree & trajectoryTree);
    Sensors generateSensors(ptree & sensorsTree);
    bool hasParsed;

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDFILEPARSER_H
