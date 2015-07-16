// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_THESAURUS_PARSER_H
#define GOODCODER_ZHENGWAIHUI_CPP_THESAURUS_PARSER_H

#include <stdint.h>
#include <fstream>
#include <string>
#include <vector>
#include "parser/parser.h"

namespace common {

// 词表解析器
class ThesaurusParser {
public:
    ThesaurusParser();
    ~ThesaurusParser();

public:
    bool init_file(const char* path_name);
    bool read_line();
    bool set_parser_interfaces(ParserInterface** parser_interfaces, uint32_t num);

private:
    bool parse_type(const std::string& line);
    bool parse_line(const std::string& line);

private:
    ParserInterface**             _parser_interfaces;
    uint32_t                      _parser_interfaces_num;
    std::vector<std::string>      _types;
    std::ifstream                 _fin;
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_THESAURUS_PARSER_H