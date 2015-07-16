// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "complex_parser.h"

namespace common {

TEST(ComplexParserTest, NormalTest) {
    ParserInterface* complex_parser = new (std::nothrow) ComplexParser();
    CHECK_NOTNULL(complex_parser);
    EXPECT_TRUE(complex_parser->parse("2|3"));
    EXPECT_EQ(2, complex_parser->get_result().complex_type.real);
    EXPECT_EQ(3, complex_parser->get_result().complex_type.imag);
}

} // common