// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "integer_parser.h"
#include <sstream>
#include "thirdparty/glog/logging.h"

namespace common {

bool IntegerParser::parse(const std::string& data) {
    std::istringstream iss(data);
    iss >> std::noskipws >> _data;
    DLOG(INFO) << "int: " << _data;
    return iss.eof() && !iss.fail();
}

DataInfo IntegerParser::get_result() {
    DataInfo data_info;
    data_info.type = DT_INT;
    data_info.int_value = _data;
    return data_info;
}

std::vector<DataInfo> IntegerParser::get_array_result() {
    LOG(ERROR) << "error: invalid operation";
    return std::vector<DataInfo>();
}

} // common