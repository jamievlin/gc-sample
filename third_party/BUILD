package(default_visibility = ["//visibility:public"])

load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "configure_make")

cmake(
    name = "gc",
    lib_source = "@gc//:all_srcs",
    out_shared_libs = ["libgc.so"],
)
