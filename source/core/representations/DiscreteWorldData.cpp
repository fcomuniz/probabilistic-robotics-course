//
// Created by francisco on 01/03/17.
//

#include "DiscreteWorldData.h"

DiscreteWorldData::DiscreteWorldData(representations::Position<int> robotRealPosition,
                                     representations::Position<int> robotEstimate,
                                     Eigen::MatrixXd fmp,
                                     Sensors sensors):robotRealPosition(robotRealPosition),
                                                      robotEstimate(robotEstimate), fmp(fmp), sensors(sensors) {

}
