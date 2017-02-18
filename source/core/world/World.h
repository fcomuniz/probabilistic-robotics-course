//
// Created by francisco on 17/02/17.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include <vector>
#include "sensor/SensorData.h"
#include "sensor/Sensor.h"

namespace world{

template<typename T>
class World {
public:
    World(){

    }

    /**
     *
     * @tparam RobotCommand (Pose2, Vector2)
     * @param commandToRobot
     * @return
     */
    template<class RobotCommand>
    std::vector<sensor::Sensor<T>> updateWorld(RobotCommand commandToRobot) {


    }




private:



};

}


#endif //PROJECT_WORLD_H
