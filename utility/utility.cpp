// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "utility.h"

namespace common {

const std::string SEPERATOR_COLON(":");
const std::string SEPERATOR_COMMA(",");
const std::string SEPERATOR_TABS("\t");
const std::string SEPERATOR_VERTICAL("|");

void split_string(
        std::vector<std::string>& vector_string,
        const std::string& line,
        const std::string& separator) {
    vector_string.clear();
    if (line.empty()) {
        return ;
    }

    size_t start = 0;
    size_t position = line.find(separator);
    while (position != std::string::npos) {
        vector_string.push_back(line.substr(start, position - start));
        start = position + separator.length();
        position = line.find(separator, start);
    }

    if (start < line.length()) {
        vector_string.push_back(line.substr(start));
    }
}

} // common