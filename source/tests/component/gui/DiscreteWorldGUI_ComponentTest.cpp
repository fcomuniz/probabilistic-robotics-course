//
// Created by francisco on 01/03/17.
//

#include "gui/DiscreteWorldGUI.h"
#include "representations/DiscreteWorldData.h"
#include "representations/Position.h"
#include <random>
#include <QApplication>

const static int N_OF_ITERATIONS = 100;

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

double sumOfDistances(representations::Position<int> estimatePosition, int nRows, int nCols){
    double sum = 0;
    for(int i = 0 ; i < nRows; i++){
        for(int j = 0 ; j < nCols; j++){
            sum += (estimatePosition -representations::Position<int>(j,i)).abs();
        }
    }
    return sum;
}

Eigen::MatrixXd generatePrettyProbabilityMatrix(representations::Position<int> estimatePosition, int nrows, int ncols){
    Eigen::MatrixXd returnMatrix = Eigen::MatrixXd::Zero(nrows, ncols);
//    Put values in matrix
    bool areValuesOk = true;
    auto sum = sumOfDistances(estimatePosition, nrows, ncols);
    for(int i = 0 ; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            double value = (estimatePosition -representations::Position<int>(j,i)).abs()/sum;
            value = std::fabs(1-value );
            areValuesOk = areValuesOk && (value <= 1);
            returnMatrix(i,j) = value;
        }
    }
    if(areValuesOk){
        std::cout << "Values are ok" << std::endl;
    } else {
        std::cout << "Values aren't ok" << std::endl;
    }
    return returnMatrix;
}

representations::Position<int> generateRandomRobotPosition(int nRows, int nCols){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disRows(0,nRows-1);
    std::uniform_int_distribution<> disCols(0,nCols-1);
    representations::Position<int> pos;
    pos.x = disCols(gen);
    pos.y = disRows(gen);
    return pos;
}


std::vector<DiscreteWorldData> generateDiscreteWorldData(){
    std::vector<DiscreteWorldData> worldData;
    int nCols = 100;
    int nRows = 200;
    for (int i = 0 ; i < N_OF_ITERATIONS; i++){
        auto estimateRobotPosition = generateRandomRobotPosition(nRows, nCols);
        Eigen::MatrixXd fdp = generatePrettyProbabilityMatrix(estimateRobotPosition,nRows,nCols);
        worldData.push_back(DiscreteWorldData(generateRandomRobotPosition(nRows,nCols), estimateRobotPosition, fdp));
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
