load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "darkSCNN_lane_detector",
    srcs = ["darkSCNN_lane_detector.cc"],
    hdrs = ["darkSCNN_lane_detector.h"],
    deps = [
        "//modules/perception/base",
        "//modules/perception/camera/common",
        "//modules/perception/camera/lib/interface",
        "//modules/perception/common/sensor_manager",
        "//modules/perception/inference:inference_factory",
        "//modules/perception/inference/utils:inference_resize_lib",
        "//modules/perception/inference/utils:inference_util_lib",
        "//modules/perception/lib/registerer",
        "//modules/perception/pipeline:stage",
        "//modules/perception/pipeline/proto/stage:darkSCNN_cc_proto",
    ],
    alwayslink = True,
)

cpplint()
