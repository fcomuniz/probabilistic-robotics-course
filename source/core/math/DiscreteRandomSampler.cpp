//
// Created by samcerq on 3/1/17.
//

#include "DiscreteRandomSampler.h"


DiscreteRandomSampler::DiscreteRandomSampler(representations::DiscreteDistribution distribution) {
    double totalSum = 0;
    for(representations::DiscreteDistribution::iterator iter = distribution.begin(); iter!= distribution.end(); ++iter){
        totalSum += iter->second;
    }
    if(abs(totalSum-1)>1e-6) {
        std::cerr<<"Invalid Probability Distribution. Sum does not add up to 1"<<std::endl;
        throw std::string("Invalid Probability Distribution. Sum does not add up to 1.");
    }

}

DiscreteRandomSampler::DiscreteRandomSampler(std::vector<representations::Position<int>> positions, std::vector<double> probs) {
    if(positions.size()!=probs.size())
        std::cerr<<"Incompatible entry sizes!"<<std::endl;
    double totalSum = 0;
    for(std::vector<double>::iterator iter=probs.begin(); iter!=probs.end(); iter++){
        totalSum+=*iter;
    }

    if(abs(totalSum-1)>1e-6) {
        std::cerr<<"Invalid Probability Distribution. Sum does not add up to 1"<<std::endl;
        throw std::string("Invalid Probability Distribution. Sum does not add up to 1.");
    }
    else {
        for (int index = 0; index < probs.size(); index++) {
            distribution.push_back(std::pair<representations::Position<int>,double>(positions[index],probs[index]));
        }
    }

}

representations::Position<int> DiscreteRandomSampler::getSample() {
    double r = ((double) rand())/(RAND_MAX);
    if(r==0)
        return distribution[0].first;
    double acc=0;
    int index = 0;
    while (index<distribution.size() && acc<r){
        acc+=distribution[index].second;
    }
    return distribution[index-1].first;
}
