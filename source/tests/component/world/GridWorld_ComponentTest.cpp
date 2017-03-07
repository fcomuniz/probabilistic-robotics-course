//
// Created by samcerq on 3/7/17.
//



#include <sensor/DiscreteSensor.h>
#include <world/GridWorld.h>

int main(){
    std::vector<sensor::DiscreteSensor> sensors;
    representations::DiscreteDistribution sensorDistribution;
    sensorDistribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,1),1));
    sensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(0,0),sensorDistribution));
    auto robotInitialPosition = itandroids_lib::math::Vector2<int>(5,5);
    world::GridWorld world(30,30, sensors, robotInitialPosition);
    std::vector<itandroids_lib::math::Vector2<int>> inputs;
    inputs.push_back(itandroids_lib::math::Vector2<int>(1,1));
    inputs.push_back(itandroids_lib::math::Vector2<int>(1,1));
    inputs.push_back(itandroids_lib::math::Vector2<int>(1,1));
    inputs.push_back(itandroids_lib::math::Vector2<int>(1,1));
    inputs.push_back(itandroids_lib::math::Vector2<int>(1,1));

    std::cout<<"Deterministic test"<<std::endl;
    for (int indexTime=0;indexTime<inputs.size();indexTime++){
        std::vector<sensor::DiscreteSensor> sensorOut = world.updateWorld(inputs[indexTime]);
        std::cout<<"Time step: "<<indexTime+1<<" Robot's position:"<<world.getGroundTruth().x<<" "<<world.getGroundTruth().y<<std::endl;
        std::cout<<"Sensor readings:"<<sensorOut[0].sensedPosition.x<<" "<<sensorOut[0].sensedPosition.y<<std::endl;

    }

    representations::DiscreteDistribution newSensorDistribution;
    newSensorDistribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,1),0.8));
    newSensorDistribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(-1,-1),0.2));
    std::vector<sensor::DiscreteSensor> newSensors;
    newSensors.push_back(sensor::DiscreteSensor(itandroids_lib::math::Vector2<int>(0,0),newSensorDistribution));
    representations::DiscreteDistribution distribution;
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,1),0.5));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(-1,-1),0.5));

    world::GridWorld randomWorld(30,30, newSensors, robotInitialPosition,distribution);
    std::cout<<"Random test"<<std::endl;
    for (int indexTime=0;indexTime<inputs.size();indexTime++){
        auto sensorOut = randomWorld.updateWorld(inputs[indexTime]);
        std::cout<<"Time step: "<<indexTime+1<<" Robot's position:"<<randomWorld.getGroundTruth().x<<" "<<randomWorld.getGroundTruth().y<<std::endl;
        std::cout<<"Sensor readings:"<<sensorOut[0].sensedPosition.x<<" "<<sensorOut[0].sensedPosition.y<<std::endl;
    }


}