// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thesaurus_parser.h"
#include <fstream>
#include "thirdparty/glog/logging.h"
#include "utility/utility.h"

namespace common {

ThesaurusParser::ThesaurusParser() {
}

ThesaurusParser::~ThesaurusParser() {
    if (_fin.is_open()) {
        _fin.close();
    }
}

bool ThesaurusParser::set_parser_interfaces(ParserInterface** parser_interfaces, uint32_t num) {
    if (parser_interfaces == NULL || num == 0) {
        return false;
    }
    _parser_interfaces = parser_interfaces;
    _parser_interfaces_num = num;
    return true;
}

bool ThesaurusParser::init_file(const char* path_name) {
    if (_fin.is_open()) {
        _fin.close();
    }
    _fin.open(path_name);
    CHECK(_fin.is_open()) << "fail to open : " << path_name;
    std::string line;
    std::getline(_fin, line);
    if (!parse_type(line)) {
        _fin.close();
        LOG(ERROR) << "error types line: " << line;
        return false;
    }
    return true;
}

bool ThesaurusParser::read_line() {
    if (!_fin.is_open()) {
        LOG(ERROR) << "file is not open";
        return false;
    }

    if (_fin.eof()) {
        LOG(WARNING) << "at the end of file, the file will be closed";
        _fin.close();
        return false;
    }

    std::string line;
    std::getline(_fin, line);
    if (!parse_line(line)) {
        LOG(ERROR) << "data is not correct : " << line;
        return false;
    }
    LOG(INFO) << "one line parse complete";
    return true;
}

bool ThesaurusParser::parse_type(const std::string& line) {
    _types.clear();
    std::vector<std::string> vector_string;
    split_string(vector_string, line, SEPERATOR_TABS);
    if (vector_string.size() != _parser_interfaces_num) {
        _fin.close();
        return false;
    }

    _types.swap(vector_string);
    return true;
}

bool ThesaurusParser::parse_line(const std::string& line) {
    std::vector<std::string> vector_string;
    split_string(vector_string, line, SEPERATOR_TABS);
    if (vector_string.size() != _parser_interfaces_num) {
        LOG(ERROR) << "data is not enough";
        return false;
    }
    for (uint32_t i = 0; i < vector_string.size(); ++i) {
        if (!_parser_interfaces[i]->parse(vector_string[i])) {
            LOG(ERROR) << "fail to parse : " << vector_string[i];
            return false;
        }
    }
    return true;
}

} // common