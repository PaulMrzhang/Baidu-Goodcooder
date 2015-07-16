// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "float_parser.h"
#include <sstream>
#include "thirdparty/glog/logging.h"

namespace common {

bool FloatParser::parse(const std::string& data) {
    std::istringstream iss(data);
    iss >> std::noskipws >> _data;
    DLOG(INFO) << "float: " << _data;
    return iss.eof() && !iss.fail();
}

DataInfo FloatParser::get_result() {
    DataInfo data_info;
    data_info.type = DT_FLOAT;
    data_info.float_value = _data;
    return data_info;
}

std::vector<DataInfo> FloatParser::get_array_result() {
    LOG(ERROR) << "error: invalid operation";
    return std::vector<DataInfo>();
}

} // common