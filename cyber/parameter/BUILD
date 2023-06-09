load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "cyber_parameter_hdrs",
    srcs = glob([
        "*.h",
    ]),
)

cc_library(
    name = "parameter",
    srcs = ["parameter.cc"],
    hdrs = ["parameter.h"],
    deps = [
        "//cyber/message:protobuf_factory",
        "//cyber/proto:parameter_cc_proto",
    ],
    alwayslink = True,
)

cc_test(
    name = "parameter_test",
    size = "small",
    srcs = ["parameter_test.cc"],
    deps = [
        "//cyber",
        "@com_google_googletest//:gtest_main",
    ],
    linkstatic = True,
)

cc_library(
    name = "parameter_client",
    srcs = ["parameter_client.cc"],
    hdrs = ["parameter_client.h"],
    deps = [
        ":parameter",
        ":parameter_service_names",
        "//cyber/node",
        "//cyber/service:client",
        "@fastrtps",
    ],
    alwayslink = True,
)

cc_test(
    name = "parameter_client_test",
    size = "small",
    srcs = ["parameter_client_test.cc"],
    deps = [
        "//cyber",
        "@com_google_googletest//:gtest_main",
    ],
    linkstatic = True,
)

cc_library(
    name = "parameter_server",
    srcs = ["parameter_server.cc"],
    hdrs = ["parameter_server.h"],
    deps = [
        ":parameter",
        ":parameter_service_names",
        "//cyber/node",
        "//cyber/service",
        "@fastrtps",
    ],
    alwayslink = True,
)

cc_test(
    name = "parameter_server_test",
    size = "small",
    srcs = ["parameter_server_test.cc"],
    deps = [
        "//cyber",
        "@com_google_googletest//:gtest_main",
    ],
    linkstatic = True,
)

cc_library(
    name = "parameter_service_names",
    hdrs = ["parameter_service_names.h"],
)

cpplint()
