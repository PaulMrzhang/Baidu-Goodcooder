// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_COMPLEX_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_COMPLEX_PARSER_H

#include "parser.h"

namespace common {

// 虚数解析器
class ComplexParser : public ParserInterface {
public:
    ComplexParser() {}
    ~ComplexParser() {}

    bool parse(const std::string& data);

    DataInfo get_result();
    std::vector<DataInfo> get_array_result();

private:
    int32_t _real;
    int32_t _imag;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_COMPLEX_PARSER_H