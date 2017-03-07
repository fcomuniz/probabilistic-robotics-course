//
// Created by samcerq on 3/1/17.
//

#include "representations/DiscreteDistribution.h"
#include <gtest/gtest.h>
using representations::DiscreteDistribution;

TEST(DiscreteDistribution_UnitTest,creation_test){
    DiscreteDistribution distribution;
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(1,0),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(-1,0),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(0,1),0.25));
    distribution.push_back(std::pair<representations::Position<int>,double>(representations::Position<int>(0,-1),0.25));
    ASSERT_EQ(distribution.size(),4);
    ASSERT_EQ(distribution[0].second,0.25);
    ASSERT_EQ(distribution[1].first.x,-1);
}