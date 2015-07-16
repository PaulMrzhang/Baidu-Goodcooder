// Copyright 2015 Baidu Inc. All Rights Reserved.
// Author: Zheng Waihui (zhengwaihui@baidu.com)

#include "thirdparty/glog/logging.h"
#include "thirdparty/gtest/gtest.h"
#include "parser/array_parser.h"
#include "parser/complex_parser.h"
#include "parser/float_parser.h"
#include "parser/integer_parser.h"
#include "parser/string_parser.h"
#include "thesaurus_parser.h"

namespace common {

TEST(ThesaurusParserTest, NormalTest) {
    ParserInterface* parser_interfaces[] = {
        new IntegerParser(),
        new FloatParser(),
        new ArrayParser<FloatParser>(),
        new StringParser(),
        new ComplexParser()
    };
    uint32_t parser_interface_size = sizeof(parser_interfaces) / sizeof(ParserInterface*);

    ThesaurusParser thesaurus_parser;
    EXPECT_TRUE(thesaurus_parser.set_parser_interfaces(parser_interfaces, parser_interface_size));
    EXPECT_TRUE(thesaurus_parser.init_file("./data.txt"));
    EXPECT_TRUE(thesaurus_parser.read_line());
    ParserInterface* int_parser = parser_interfaces[0];
    EXPECT_EQ(2, int_parser->get_result().int_value);
    EXPECT_FALSE(thesaurus_parser.read_line());
}

} // common