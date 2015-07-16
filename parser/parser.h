// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_PARSER_H

#include <string>
#include <vector>
#include "../utility/data_type.h"

namespace common {

// 类型解析器接口
class ParserInterface {
public:
    ParserInterface() {}
    virtual ~ParserInterface() {}

    virtual bool parse(const std::string& data) = 0;

    virtual DataInfo get_result() = 0;
    virtual std::vector<DataInfo> get_array_result() = 0;
};

// 解析器工厂
template <typename T>
class ParserFactory {
public:
    static ParserInterface* create_parser() {
        return new T();
    }
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_PARSER_H