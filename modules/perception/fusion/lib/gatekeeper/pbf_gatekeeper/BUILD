load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "pbf_gatekeeper",
    srcs = ["pbf_gatekeeper.cc"],
    hdrs = ["pbf_gatekeeper.h"],
    deps = [
        "//modules/common/util",
        "//modules/perception/fusion/base:base_init_options",
        "//modules/perception/fusion/base:scene",
        "//modules/perception/fusion/base:track",
        "//modules/perception/fusion/lib/interface",
        "//modules/perception/lib/config_manager",
        "//modules/perception/pipeline/proto/plugin:pbf_gatekeeper_config_cc_proto",
    ],
)

# todo(zero)
# cc_test(
#     name = "pbf_gatekeeper_test",
#     size = "small",
#     srcs = ["pbf_gatekeeper_test.cc"],
#     deps = [
#         ":pbf_gatekeeper",
#         "//modules/perception/common/sensor_manager",
#         "//modules/perception/fusion/base:sensor",
#         "//modules/perception/fusion/base:track",
#         "@com_google_googletest//:gtest_main",
#     ],
# )

cpplint()
