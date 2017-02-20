//
// Created by francisco on 17/02/17.
//

#include "GridWorld.h"

namespace world{

GridWorld::GridWorld(int rows, int cols, std::vector<sensor::Sensor<int>> sensors) : World(sensors), rows(rows), cols(cols){

}
}