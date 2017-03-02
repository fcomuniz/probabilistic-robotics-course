//
// Created by francisco on 01/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H

#include <fstream>
#include "utils/parser/DiscreteWorldFileParser.h"
#include "representations/DiscreteWorldData.h"

using utils::DiscreteWorldFileParser;

namespace applications{
class DiscreteWorld_main{
public:
    DiscreteWorld_main(){
//        Open Discrete world file
        std::ifstream confFile(configurationPath + "DiscreteWorldConfiguration.txt");
        parseConfFile(confFile);

    }
    /**
     * This is the method for running the simulation and generating the world data;
     */
    void run(){

    }

    const std::vector<DiscreteWorldData> & getWorldData(){
        return worldData;
    }

private:
    static const std::string configurationPath ;
    void parseConfFile(std::ifstream & confFile){
//        Read the configuration file
        DiscreteWorldFileParser parser;
        parser.parse(confFile);
        configurationData = parser.getConfigurationData();
    }

    utils::DiscreteWorldConfigurationData configurationData;
    std::vector<DiscreteWorldData> worldData;
};
    const std::string DiscreteWorld_main::configurationPath = std::string("../configuration/discrete_world");
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H
