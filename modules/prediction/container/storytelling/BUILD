load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "storytelling_container",
    srcs = ["storytelling_container.cc"],
    hdrs = ["storytelling_container.h"],
    copts = [
        "-DMODULE_NAME=\\\"prediction_container\\\"",
    ],
    deps = [
        "//modules/prediction/common:prediction_map",
        "//modules/prediction/container",
        "//modules/common_msgs/storytelling_msgs:story_cc_proto",
    ],
)

cpplint()
