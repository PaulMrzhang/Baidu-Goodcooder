// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "float_parser.h"

namespace common {

TEST(FloatParserTest, NormalTest) {
    ParserInterface* float_parser = new (std::nothrow) FloatParser();
    CHECK_NOTNULL(float_parser);
    EXPECT_TRUE(float_parser->parse("3.14"));
    EXPECT_FLOAT_EQ(3.14, float_parser->get_result().float_value);
}

} // common