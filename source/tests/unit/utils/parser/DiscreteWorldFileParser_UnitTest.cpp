//
// Created by francisco on 02/03/17.
//

#include "DiscreteWorldFileParser_UnitTest.h"
#include <gtest/gtest.h>
#include "utils/parser/DiscreteWorldFileParser.h"

using utils::DiscreteWorldFileParser;

DiscreteWorldFileParser generateUsedParser(){
    DiscreteWorldFileParser parser;
    std::ifstream file("simple_parse_file.txt");
    parser.parse(file);
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

}


TEST(DiscreteWorldFileParser_UnitTest, checkSimpleConfigurationData){
    auto parser = generateUsedParser();
    checkSimpleConfigurationData(parser.getConfigurationData());
}
