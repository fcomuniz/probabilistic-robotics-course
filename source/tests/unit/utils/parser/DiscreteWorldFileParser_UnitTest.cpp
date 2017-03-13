//
// Created by francisco on 02/03/17.
//

#include "DiscreteWorldFileParser_UnitTest.h"
#include <gtest/gtest.h>
#include "utils/parser/DiscreteWorldFileParser.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using utils::DiscreteWorldFileParser;
namespace pt = boost::property_tree;

DiscreteWorldFileParser generateUsedParser(){
    DiscreteWorldFileParser parser;
    pt::ptree tree;
    pt::read_json("simpleworldtest.json", tree);
    parser.parse(tree);
    return parser;
}



TEST(DiscreteWorldFileParser_UnitTest, simpleParseTest){
    auto parser = generateUsedParser();
    SUCCEED();
}

TEST(DiscreteWorldFileParser_UnitTest, check_for_throw_test){
    DiscreteWorldFileParser parser;
    //Trying to acess the data before parsing
    try {
        parser.getConfigurationData();
    } catch (const std::runtime_error & runtime_error){
        SUCCEED();
    } catch (const std::exception & exception){
        FAIL();
    }
}

void checkSimpleConfigurationData(utils::DiscreteWorldConfigurationData configurationData){
    EXPECT_EQ(configurationData.worldHeight, 20);
    EXPECT_EQ(configurationData.worldWidth, 30);
}


TEST(DiscreteWorldFileParser_UnitTest, checkSimpleConfigurationData){
    auto parser = generateUsedParser();
    checkSimpleConfigurationData(parser.getConfigurationData());
}
