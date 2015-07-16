// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "array_parser.h"
#include "integer_parser.h"

namespace common {

TEST(ArrayParserTest, NormalTest) {
    ParserInterface* array_int = new (std::nothrow) ArrayParser<IntegerParser>();
    CHECK_NOTNULL(array_int);
    EXPECT_TRUE(array_int->parse("2:3,4"));
    std::vector<DataInfo> data = array_int->get_array_result();
    EXPECT_EQ(3, data[0].int_value);
    EXPECT_EQ(4, data[1].int_value);
}

} // common
