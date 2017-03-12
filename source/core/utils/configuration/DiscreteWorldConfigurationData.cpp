//
// Created by francisco on 02/03/17.
//

#include "DiscreteWorldConfigurationData.h"

namespace utils{

DiscreteWorldConfigurationData::DiscreteWorldConfigurationData(): worldWidth(0), worldHeight(0) {

}

DiscreteWorldConfigurationData::DiscreteWorldConfigurationData(int worldWidth, int worldHeight,
                                                               representations::DiscreteTrajectory trajectory,
                                                               Sensors sensor
                                                                , representations::Position<int> robotPosition):
        worldHeight(worldHeight), worldWidth(worldWidth), trajectory(trajectory), sensors(sensors), robotPosition(robotPosition) {

    checkSensorsPositions();
}

void DiscreteWorldConfigurationData::checkSensorsPositions() {
    for(auto & sensor : sensors){
        checkSensorPosition(sensor);
    }
}

void DiscreteWorldConfigurationData::checkSensorPosition(sensor::DiscreteSensor &sensor) {
    if(sensor.position.x < 0 || sensor.position.x > worldWidth || sensor.position.y < 0 || sensor.position.y > worldHeight)
        throw std::runtime_error("Invalid Sensors");
}


}