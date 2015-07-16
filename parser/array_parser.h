// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_PARSER_ARRAY_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_PARSER_ARRAY_PARSER_H

#include <sstream>
#include "../utility/utility.h"
#include "parser.h"

namespace common {

// 模板类：包装内置类型及用户自定义类型成数组
// 作用：解析数组类型
template <typename T>
class ArrayParser : public ParserInterface {
public:
    ArrayParser() {}
    ~ArrayParser() {}

    bool parse(const std::string& data) {
        _data.clear();
        size_t position = data.find(SEPERATOR_COLON);

        uint32_t vector_size = 0;
        std::istringstream iss(data.substr(0, position));
        iss >> std::noskipws >> vector_size;
        if (!iss.eof() || iss.fail()) {
            LOG(ERROR) << "invalid data : " << data;
            return false;
        }

        std::string elements_string = data.substr(position+1);
        std::vector<std::string> vector_string;
        split_string(vector_string, elements_string, SEPERATOR_COMMA);
        if (vector_string.size() != vector_size) {
            LOG(ERROR) << "invalid : " << data;
            return false;
        }

        // 依次解析数组元素
        for (uint32_t i = 0; i < vector_string.size(); ++i) {
            T parser;
            if (!parser.parse(vector_string[i])) {
                LOG(ERROR) << "can not parse : " << data;
                _data.clear();
                return false;
            }
            _data.push_back(parser.get_result());
        }

        return true;
    }

    DataInfo get_result() {
        LOG(ERROR) << "error: invalid operation";
        return DataInfo();
    }

    std::vector<DataInfo> get_array_result() {
        return _data;
    }

private:
    std::vector<DataInfo> _data;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_PARSER_ARRAY_PARSER_H
