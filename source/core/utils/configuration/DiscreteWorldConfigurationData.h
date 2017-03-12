//
// Created by francisco on 02/03/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDCONFIGURATIONDATA_H
#define ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDCONFIGURATIONDATA_H

#include "representations/DiscreteTrajectory.h"
#include "sensor/DiscreteSensor.h"


using Sensors = std::vector<sensor::DiscreteSensor>;

namespace utils{

class DiscreteWorldConfigurationData {
public:
    DiscreteWorldConfigurationData();
    DiscreteWorldConfigurationData(int worldWidth, int worldHeight, representations::DiscreteTrajectory trajectory, Sensors sensors, representations::Position<int> robotPosition);


    int worldWidth;
    int worldHeight;
    representations::Position <int> robotPosition;
    representations::DiscreteTrajectory trajectory;
    Sensors sensors;

private:
    void checkSensorsPositions();
    void checkSensorPosition(sensor::DiscreteSensor & sensor);

};
}


#endif //ROBOTICS_PROBABILISTICS_COURSE_DISCRETEWORLDCONFIGURATIONDATA_H
