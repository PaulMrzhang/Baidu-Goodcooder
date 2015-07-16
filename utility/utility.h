// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_UTILITY_UTILITY_H
#define GOODCODER_ZHENGWAIHUI_CPP_UTILITY_UTILITY_H

#include <stdint.h>
#include <string>
#include <vector>

namespace common {

extern const std::string SEPERATOR_COLON;
extern const std::string SEPERATOR_COMMA;
extern const std::string SEPERATOR_TABS;
extern const std::string SEPERATOR_VERTICAL;

// 切割字符串函数
void split_string(
        std::vector<std::string>& vector_string,
        const std::string& line,
        const std::string& separator);

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_UTILITY_UTILITY_H