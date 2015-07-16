// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "string_parser.h"

namespace common {

TEST(StringParserTest, NormalTest) {
    ParserInterface* string_parser = new (std::nothrow) StringParser();
    CHECK_NOTNULL(string_parser);
    EXPECT_TRUE(string_parser->parse("hello world"));
    char* ptr = string_parser->get_result().char_ptr;
    CHECK_NOTNULL(ptr);
    EXPECT_STREQ("hello world", ptr);
    delete ptr;
    ptr = NULL;
}

} // common