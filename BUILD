cc_binary(
    name = 'demo',
    srcs = 'main.cpp',
    deps = [
        ':http_lib',
        ':thesaurus_parser'
    ],
    testdata = ['data.txt']
)

cc_test(
    name = 'thesaurus_parser_test',
    srcs = 'thesaurus_parser_test.cpp',
    deps = [
        ':http_lib',
        ':thesaurus_parser'
    ],
    testdata = ['data.txt']
)
cc_library(
    name = 'thesaurus_parser',
    srcs = 'thesaurus_parser.cpp',
    deps = [
        ':http_lib',
        '//itc/goodcooder/parser:complex_parser',
        '//itc/goodcooder/parser:integer_parser',
        '//itc/goodcooder/parser:float_parser',
        '//itc/goodcooder/parser:string_parser',
    ]
)

cc_library(
    name = 'http_lib',
    deps = [
        '//thirdparty/glog:glog',
        '//thirdparty/gtest:gtest'
    ]
)
