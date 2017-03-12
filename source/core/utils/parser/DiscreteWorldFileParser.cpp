//
// Created by francisco on 02/03/17.
//

#include "DiscreteWorldFileParser.h"
namespace utils{

DiscreteWorldFileParser::DiscreteWorldFileParser(): hasParsed(false) {


}
void DiscreteWorldFileParser::parse(std::ifstream &confFile) {

    hasParsed = true;
}

DiscreteWorldConfigurationData DiscreteWorldFileParser::getConfigurationData() {
    if(!hasParsed)
        throw std::runtime_error("Hasn't parsed configuration file yet");
    return DiscreteWorldConfigurationData();
}

void DiscreteWorldFileParser::parse(ptree &tree) {

}


}
