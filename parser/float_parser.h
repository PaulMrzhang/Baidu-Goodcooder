// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_FLOAT_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_FLOAT_PARSER_H

#include "parser.h"

namespace common {

// 浮点型解析器
class FloatParser : public ParserInterface {
public:
    FloatParser() : _data(0.0) {}
    ~FloatParser() {}

    bool parse(const std::string& data);

    DataInfo get_result();
    std::vector<DataInfo> get_array_result();

private:
    float _data;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_FLOAT_PARSER_H