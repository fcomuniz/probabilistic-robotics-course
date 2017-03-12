//
// Created by francisco on 01/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H

#include <fstream>
#include "utils/parser/DiscreteWorldFileParser.h"
#include "representations/DiscreteWorldData.h"
#include "world/GridWorld.h"
#include "estimation/DiscreteWorldEstimator.h"
#include "utils/configuration/DiscreteWorldConstants.h"

using utils::DiscreteWorldFileParser;
using pt = boost::property_tree::ptree;
using World = world::GridWorld;

namespace applications{
class DiscreteWorld_main{
public:
    DiscreteWorld_main(){
//        Open Discrete world file
        pt propTree(configurationPath + "DiscreteWorldConfiguration.json");
        parseConfFile(propTree);

    }
    /**
     * This is the method for running the simulation and generating the world data;
     */
    void run(){
        World world(configurationData.worldWidth, configurationData.worldHeight, configurationData.sensors, configurationData.robotPosition);
        estimation::DiscreteWorldEstimator estimator;
        for(auto & stepInTrajectory : configurationData.trajectory){
            auto sensors = world.updateWorld(stepInTrajectory);
            estimator.estimate(world, sensors);
            auto estimate = estimator.getWorldEstimate();
            worldData.push_back(DiscreteWorldData(world.getGroundTruth(), estimate.robotPosition, estimate.estimateMatrix, sensors));
        }
    }

    const std::vector<DiscreteWorldData> & getWorldData(){
        return worldData;
    }

    static const std::string configurationPath ;
private:
    void parseConfFile(pt & ptree){
//        Read the configuration file
        DiscreteWorldFileParser parser;
        parser.parse(ptree);
        configurationData = parser.getConfigurationData();
    }

    utils::DiscreteWorldConfigurationData configurationData;
    std::vector<DiscreteWorldData> worldData;
};
    const std::string DiscreteWorld_main::configurationPath = utils::configurationPath;

}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLD_MAIN_H
