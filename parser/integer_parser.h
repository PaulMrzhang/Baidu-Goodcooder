// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_INTEGER_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_INTEGER_PARSER_H

#include "parser.h"

namespace common {

// 整型解析器
class IntegerParser : public ParserInterface {
public:
    IntegerParser() : _data(0) {}
    ~IntegerParser() {}

    bool parse(const std::string& data);

    DataInfo get_result();
    std::vector<DataInfo> get_array_result();

private:
    int32_t _data;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_INTEGER_PARSER_H