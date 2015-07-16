// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "complex_parser.h"
#include <sstream>
#include "thirdparty/glog/logging.h"
#include "../utility/utility.h"

namespace common {

bool ComplexParser::parse(const std::string& data) {
    size_t position = data.find(SEPERATOR_VERTICAL);
    if (position == std::string::npos ||
            position == (data.length() - 1) ||
            position == 0) {
        _real = 0;
        _imag = 0;
        return false;
    }

    std::istringstream iss_real(data.substr(0, position));
    iss_real >> std::noskipws >> _real;
    DLOG(INFO) << _real;
    if (!iss_real.eof() || iss_real.fail()) {
        _real = 0;
        _imag = 0;
        return false;
    }

    std::istringstream iss_imag(data.substr(position+1));
    iss_imag >> std::noskipws >> _imag;
    DLOG(INFO) << _imag;
    if (!iss_imag.eof() || iss_imag.fail()) {
        _real = 0;
        _imag = 0;
        return false;
    }

    return true;
}

DataInfo ComplexParser::get_result() {
    DataInfo data_info;
    data_info.type = DT_COMPLEX;
    data_info.complex_type.real = _real;
    data_info.complex_type.imag = _imag;
    return data_info;
}

std::vector<DataInfo> ComplexParser::get_array_result() {
    LOG(ERROR) << "error: invalid operation";
    return std::vector<DataInfo>();
}

} // common