// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include <string>
#include <vector>
#include "thirdparty/gtest/gtest.h"
#include "utility.h"

namespace common {

TEST(UtilityTest, NormalTest) {
    std::string line("abc,bcd");
    std::vector<std::string> vector_string;
    split_string(vector_string, line, SEPERATOR_COMMA);
    EXPECT_EQ(2, vector_string.size());
    EXPECT_STREQ("abc", vector_string[0].c_str());
    EXPECT_STREQ("bcd", vector_string[1].c_str());
}

} // common