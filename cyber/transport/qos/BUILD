load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools:cpplint.bzl", "cpplint")

filegroup(
    name = "cyber_transport_qos_hdrs",
    srcs = glob([
        "*.h",
    ]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "qos",
    visibility = ["//visibility:public"],
    deps = [
        ":qos_profile_conf",
    ],
)

cc_library(
    name = "qos_profile_conf",
    srcs = ["qos_profile_conf.cc"],
    hdrs = ["qos_profile_conf.h"],
    deps = [
        "//cyber/proto:qos_profile_cc_proto",
    ],
)

cpplint()
