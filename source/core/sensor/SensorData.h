//
// Created by francisco on 17/02/17.
//

#ifndef ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H
#define ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H

namespace sensor{


template <typename T>
struct SensorData {

};

template<>
struct SensorData<int>{

};

template<>
struct SensorData<double>{
};


}


#endif //ROBOTICS_PROBABILISTICS_COURSE_SENSORDATA_H
