//
// Created by francisco on 17/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H

namespace sensor{

template <typename T>
class SensorData {

};

template<>
class SensorData<int>{

};

template<>
class SensorData<double>{
};


}


#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H
