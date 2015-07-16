cc_test(
    name = 'utility_test',
    srcs = 'utility_test.cpp',
    deps = [
        ':http_lib',
        ':utility'
    ]
)
cc_library(
    name = 'utility',
    srcs = 'utility.cpp',
    deps = [
    ]
)

cc_library(
    name = 'http_lib',
    deps = [
        '//thirdparty/glog:glog',
        '//thirdparty/gtest:gtest'
    ]
)
