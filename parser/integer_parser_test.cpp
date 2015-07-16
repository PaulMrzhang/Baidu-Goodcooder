// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "integer_parser.h"

namespace common {

TEST(IntegerParserTest, NormalTest) {
    ParserInterface* int_parser = new (std::nothrow) IntegerParser();
    CHECK_NOTNULL(int_parser);
    EXPECT_TRUE(int_parser->parse("123"));
    EXPECT_EQ(123, int_parser->get_result().int_value);
}

} // common