load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "extrapolation_predictor",
    srcs = ["extrapolation_predictor.cc"],
    hdrs = ["extrapolation_predictor.h"],
    copts = [
        "-DMODULE_NAME=\\\"prediction\\\"",
    ],
    deps = [
        "//modules/common/math",
        "//modules/prediction/common:prediction_gflags",
        "//modules/prediction/common:prediction_map",
        "//modules/prediction/common:prediction_util",
        "//modules/prediction/container/obstacles:obstacle_clusters",
        "//modules/prediction/container/obstacles:obstacles_container",
        "//modules/prediction/predictor/sequence:sequence_predictor",
        "//modules/common_msgs/prediction_msgs:lane_graph_cc_proto",
    ],
)

cpplint()
