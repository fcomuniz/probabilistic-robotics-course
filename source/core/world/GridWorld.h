//
// Created by francisco on 17/02/17.
//

#ifndef PROJECT_GRIDWORLD_H
#define PROJECT_GRIDWORLD_H


#include "world/World.h"
namespace world{

class GridWorld :public World<int>{
public:
    GridWorld(int rows, int cols, std::vector<sensor::Sensor<int>> sensors);



private:
    const int rows;
    const int cols;
};
}


#endif //PROJECT_GRIDWORLD_H
