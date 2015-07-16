cc_test(
    name = 'array_parser_test',
    srcs = 'array_parser_test.cpp',
    deps = [
        ':http_lib',
        ':integer_parser',
        '//itc/goodcooder/utility:utility'
    ]
)

cc_test(
    name = 'complex_parser_test',
    srcs = 'complex_parser_test.cpp',
    deps = [
        ':http_lib',
        ':complex_parser'
    ]
)
cc_library(
    name = 'complex_parser',
    srcs = 'complex_parser.cpp',
    deps = [
        ':http_lib',
        '//itc/goodcooder/utility:utility'
    ]
)

cc_test(
    name = 'float_parser_test',
    srcs = 'float_parser_test.cpp',
    deps = [
        ':http_lib',
        ':float_parser'
    ]
)
cc_library(
    name = 'float_parser',
    srcs = 'float_parser.cpp',
    deps = [
        ':http_lib',
    ]
)

cc_test(
    name = 'integer_parser_test',
    srcs = 'integer_parser_test.cpp',
    deps = [
        ':http_lib',
        ':integer_parser'
    ]
)
cc_library(
    name = 'integer_parser',
    srcs = 'integer_parser.cpp',
    deps = [
        ':http_lib'
    ]
)

cc_test(
    name = 'string_parser_test',
    srcs = 'string_parser_test.cpp',
    deps = [
        ':string_parser',
        ':http_lib'
    ]
)
cc_library(
    name = 'string_parser',
    srcs = 'string_parser.cpp',
    deps = [
        ':http_lib'
    ]
)

cc_library(
    name = 'http_lib',
    deps = [
        '//thirdparty/glog:glog',
        '//thirdparty/gtest:gtest'
    ]
)
