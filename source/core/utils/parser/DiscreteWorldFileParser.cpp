//
// Created by francisco on 02/03/17.
//

#include <utils/configuration/DiscreteWorldConstants.h>
#include "DiscreteWorldFileParser.h"
#include "utils/configuration/DiscreteWorldConfigurationData.h"
namespace utils{

DiscreteWorldFileParser::DiscreteWorldFileParser(): hasParsed(false) {


}
void DiscreteWorldFileParser::parse(std::ifstream &confFile) {

    hasParsed = true;
}

DiscreteWorldConfigurationData DiscreteWorldFileParser::getConfigurationData() {
    if(!hasParsed)
        throw std::runtime_error("Hasn't parsed configuration file yet");
    return *data;
}

void DiscreteWorldFileParser::parse(ptree &tree) {
// Open some other ptrees
    auto filename = tree.get<std::string>("world");

    ptree worldTree(utils::configurationPath + "/world/" + filename);
    parseWorldTree(worldTree);
}

void DiscreteWorldFileParser::parseWorldTree(ptree &tree) {
    auto nCols = tree.get<int>("width");
    auto nRows = tree.get<int>("height");
    auto trajectoryFilename = tree.get<std::string>("trajectory");
    ptree trajectoryTree(utils::configurationPath + "/trajectories/" + trajectoryFilename);
    auto trajectory = generateTrajectory(trajectoryTree);
    auto robotInitialPosition = generateInitialRobotPosition(trajectoryTree);
    auto sensorsFilename = tree.get<std::string>("sensor");
    ptree sensorTree(utils::configurationPath + "/sensors/" + sensorsFilename);
    auto sensors = generateSensors(sensorTree);
    data = std::make_shared<DiscreteWorldConfigurationData>(nRows, nCols, trajectory, sensors, robotInitialPosition);
}

representations::DiscreteTrajectory DiscreteWorldFileParser::generateTrajectory(ptree &trajectoryTree) {
    return representations::DiscreteTrajectory();
}

Sensors DiscreteWorldFileParser::generateSensors(ptree &sensorsTree) {
    return Sensors();
}

representations::Position<int> DiscreteWorldFileParser::generateInitialRobotPosition(ptree &) {
    return representations::Position<int>();
}


}
