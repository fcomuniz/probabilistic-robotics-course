//
// Created by francisco on 17/02/17.
//

#ifndef PROJECT_WORLD_H
#define PROJECT_WORLD_H

#include <vector>
#include "sensor/SensorData.h"
#include "sensor/Sensor.h"
#include "robot/Robot.h"
#include "representations/Position.h"


namespace world{

template<typename T>
class World {
public:
    World(std::vector<sensor::Sensor<T>> sensors): sensors(sensors){

    }



    /**
     *
     * @tparam RobotCommand (Pose2, Vector2)
     * @param commandToRobot
     * @return
     */
    template<class RobotCommand>
    std::vector<sensor::Sensor<T>> updateWorld(RobotCommand commandToRobot) {

        updateRobotPosition(commandToRobot);
        for(auto & sensor : sensors){
//           sensor.updateSensedPosition(robotPosition);
        }
        return sensors;
    }



protected:

    template<class RobotCommand>
    void updateRobotPosition(RobotCommand commandToRobot){

    }

private:
    std::vector<sensor::Sensor<T>> sensors;
};

}


#endif //PROJECT_WORLD_H
