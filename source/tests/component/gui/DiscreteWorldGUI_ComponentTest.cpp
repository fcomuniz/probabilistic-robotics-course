//
// Created by francisco on 01/03/17.
//

#include "gui/DiscreteWorldGUI.h"
#include "representations/DiscreteWorldData.h"
#include "representations/Position.h"
#include <random>
#include <QApplication>


Eigen::MatrixXd generateRandomProbabilityMatrix(int nrows, int ncols){
    Eigen::MatrixXd returnMatrix = Eigen::MatrixXd::Zero(nrows, ncols);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0,1);
    for(int i = 0 ; i < nrows ; i++){
        for (int j = 0 ; j < ncols ; j++){
           returnMatrix(i,j) = dis(gen);
        }
    }
    return returnMatrix;
}

representations::Position<int> generateRandomRobotPosition(int nRows, int nCols){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disRows(0,nRows);
    std::uniform_int_distribution<> disCols(0,nCols);
    representations::Position<int> pos;
    pos.x = disCols(gen);
    pos.y = disRows(gen);
    return pos;
}


std::vector<DiscreteWorldData> generateDiscreteWorldData(){
    std::vector<DiscreteWorldData> worldData;
    int nCols = 10;
    int nRows = 20;
    for (int i = 0 ; i < 20; i++){
        Eigen::MatrixXd fdp = generateRandomProbabilityMatrix(nRows,nCols);
        worldData.push_back(DiscreteWorldData(generateRandomRobotPosition(nRows,nCols), generateRandomRobotPosition(nRows,nCols), fdp));
    }
    return worldData;
}


int main(int argc, char ** argv){
    auto worldData = generateDiscreteWorldData();
#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    QApplication::setGraphicsSystem("raster");
#endif
    QApplication a(argc, argv);
    DiscreteWorldGUI gui;
    gui.setWorldData(worldData);
    gui.show();
    return a.exec();
}
