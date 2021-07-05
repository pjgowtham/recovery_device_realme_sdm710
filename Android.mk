LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),realme_sdm710)
include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif
