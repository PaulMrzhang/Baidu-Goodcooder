// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "string_parser.h"
#include <stdio.h>
#include "thirdparty/glog/logging.h"

namespace common {

bool StringParser::parse(const std::string& data) {
    _data = data;
    return true;
}

DataInfo StringParser::get_result() {
    DataInfo data_info;
    data_info.type = DT_STRING;
    data_info.char_ptr = NULL;
    char* ptr = new (std::nothrow) char[_data.size()+1];
    if (ptr == NULL) {
        LOG(ERROR) << "error: system has not enough memory!";
        return data_info;
    }
    snprintf(ptr, _data.size()+1, "%s", _data.c_str());
    DLOG(INFO) << "string: " << ptr;
    data_info.char_ptr = ptr;
    return data_info;
}

std::vector<DataInfo> StringParser::get_array_result() {
    LOG(ERROR) << "error: invalid operation";
    return std::vector<DataInfo>();
}

} // common