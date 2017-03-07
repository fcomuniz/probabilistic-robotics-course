//
// Created by samcerq on 3/1/17.
//

#include "math/DiscreteRandomSampler.h"
#include <gtest/gtest.h>

TEST(DiscreteRandomSampler_UnitTest,creation_test){
    representations::DiscreteDistribution distribution;

    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,0),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(-1,0),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(0,1),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(0,-1),0.25));

    DiscreteRandomSampler sampler(distribution);

    std::vector<representations::Position<int>> positions;
    positions.push_back(representations::Position<int>(1,0));
    positions.push_back(representations::Position<int>(-1,0));
    positions.push_back(representations::Position<int>(0,0));

    std::vector<double> probs;
    probs.push_back(0.25);
    probs.push_back(0.25);
    probs.push_back(0.5);

    DiscreteRandomSampler secondSampler(positions,probs);

    std::vector<representations::Position<int>> deterministicPos;
    deterministicPos.push_back(representations::Position<int>(1,2));
    std::vector<double> deterministicProb;
    deterministicProb.push_back(1.0);
    DiscreteRandomSampler thirdSampler(deterministicPos,deterministicProb);
    representations::Position<int> sample = thirdSampler.getSample();
    ASSERT_EQ(sample.x,1);
    ASSERT_EQ(sample.y,2);

}