// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include <stdint.h>
#include <iostream>
#include "thirdparty/glog/logging.h"
#include "parser/array_parser.h"
#include "parser/complex_parser.h"
#include "parser/float_parser.h"
#include "parser/integer_parser.h"
#include "parser/string_parser.h"
#include "thesaurus_parser.h"

int32_t main(int32_t argc, char* argv[]) {
    google::InitGoogleLogging(argv[0]);

    common::ParserInterface* parser_interfaces[] = {
        common::ParserFactory<common::IntegerParser>::create_parser(),
        common::ParserFactory<common::FloatParser>::create_parser(),
        common::ParserFactory<common::ArrayParser<common::FloatParser> >::create_parser(),
        common::ParserFactory<common::StringParser>::create_parser(),
        common::ParserFactory<common::ComplexParser>::create_parser(),
    };
    uint32_t parser_interface_size = sizeof(parser_interfaces) / sizeof(common::ParserInterface*);

    common::ThesaurusParser thesaurus_parser;
    thesaurus_parser.set_parser_interfaces(parser_interfaces, parser_interface_size);
    thesaurus_parser.init_file("./data.txt");

    if (thesaurus_parser.read_line()) {
        common::DataInfo data_info1 = parser_interfaces[0]->get_result();
        if (data_info1.type == common::DT_INT) {
            std::cout << data_info1.int_value << std::endl;
        } else {
            std::cout << "wrong parser" << std::endl;
        }

        common::DataInfo data_info2 = parser_interfaces[4]->get_result();
        if (data_info2.type == common::DT_COMPLEX) {
            std::cout << data_info2.complex_type.real << " : "
                      << data_info2.complex_type.imag << std::endl;
        } else {
            std::cout << "wrong parser" << std::endl;
        }
    }

    for (uint32_t i = 0; i < parser_interface_size; ++i) {
        delete parser_interfaces[i];
        parser_interfaces[i] = NULL;
    }

    return 0;
}