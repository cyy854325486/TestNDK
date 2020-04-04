#Android.mk
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := nativelib

LOCAL_SRC_FILES := NativeApi.cpp
NDK_APP_DST_DIR := ../../libs/$(TARGET_ARCH_ABI)
include $(BUILD_SHARED_LIBRARY)