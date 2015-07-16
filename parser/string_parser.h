// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_STRING_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_STRING_PARSER_H

#include "parser.h"

namespace common {

// 字符串解析器
class StringParser : public ParserInterface {
public:
    StringParser() {}
    ~StringParser() {}

    bool parse(const std::string& data);

    DataInfo get_result();
    std::vector<DataInfo> get_array_result();

private:
    std::string _data;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_STRING_PARSER_H