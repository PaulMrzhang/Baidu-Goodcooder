// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#ifndef GOODCODER_ZHENGWAIHUI_CPP_UTILITY_DATA_TYPE_H
#define GOODCODER_ZHENGWAIHUI_CPP_UTILITY_DATA_TYPE_H

#include <stdint.h>

namespace common {

enum DataType {
    DT_INT = 0,
    DT_FLOAT = 1,
    DT_STRING = 2,
    DT_COMPLEX = 3,

    UNKNOWN_DATA = 100
};

struct ComplexType {
    int32_t real;
    int32_t imag;
};

struct DataInfo {
    DataType type;
    union {
        int32_t int_value;
        float float_value;
        char* char_ptr;
        ComplexType complex_type;
    };
};

} // common

#endif // GOODCODER_ZHENGWAIHUI_CPP_UTILITY_DATA_TYPE_H