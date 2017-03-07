//
// Created by samcerq on 3/7/17.
//



#include <sensor/DiscreteSensor.h>
#include <world/GridWorld.h>

int main(){
    std::vector<sensor::DiscreteSensor> sensors;
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
        world.updateWorld(inputs[indexTime]);
        std::cout<<"Time step: "<<indexTime+1<<" Robot's position:"<<world.getGroundTruth().x<<" "<<world.getGroundTruth().y<<std::endl;
    }

    representations::DiscreteDistribution distribution;
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,1),0.5));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(-1,-1),0.5));

    world::GridWorld randomWorld(30,30, sensors, robotInitialPosition,distribution);
    std::cout<<"Random test"<<std::endl;
    for (int indexTime=0;indexTime<inputs.size();indexTime++){
        randomWorld.updateWorld(inputs[indexTime]);
        std::cout<<"Time step: "<<indexTime+1<<" Robot's position:"<<randomWorld.getGroundTruth().x<<" "<<randomWorld.getGroundTruth().y<<std::endl;
    }


}