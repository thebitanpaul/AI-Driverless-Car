## Auto generated by `proto_build_generator.py`
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("//tools:python_rules.bzl", "py_proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "radar_obstacle_cc_proto",
    deps = [
        ":radar_obstacle_proto",
    ],
)

proto_library(
    name = "radar_obstacle_proto",
    srcs = ["radar_obstacle.proto"],
    deps = [
        "//modules/common_msgs/basic_msgs:error_code_proto",
        "//modules/common_msgs/basic_msgs:header_proto",
        "//modules/common_msgs/perception_msgs:perception_obstacle_proto",
        "//modules/common_msgs/basic_msgs:geometry_proto",
    ],
)

py_proto_library(
    name = "radar_obstacle_py_pb2",
    deps = [
        ":radar_obstacle_proto",
        "//modules/common_msgs/basic_msgs:error_code_py_pb2",
        "//modules/common_msgs/basic_msgs:header_py_pb2",
        "//modules/common_msgs/perception_msgs:perception_obstacle_py_pb2",
        "//modules/common_msgs/basic_msgs:geometry_py_pb2",
    ],
)

cc_proto_library(
    name = "third_party_perception_component_cc_proto",
    deps = [
        ":third_party_perception_component_proto",
    ],
)

proto_library(
    name = "third_party_perception_component_proto",
    srcs = ["third_party_perception_component.proto"],
)

py_proto_library(
    name = "third_party_perception_component_py_pb2",
    deps = [
        ":third_party_perception_component_proto",
    ],
)
