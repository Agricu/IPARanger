export TARGET = iphone:clang:14.5:14.5
INSTALL_TARGET_PROCESSES = IPARanger
ARCHS = arm64 arm64e

ifeq ($(THEOS_PACKAGE_SCHEME),rootless)
    CFLAGS += -DTHEOS_PACKAGE_SCHEME_rootless
endif

include $(THEOS)/makefiles/common.mk
GO_EASY_ON_ME = 1
APPLICATION_NAME = IPARanger
DEBUG = 1

SOURCES = $(shell find . -name 'IPAR*.m')

IPARanger_FILES = main.m $(SOURCES)
IPARanger_FRAMEWORKS = UIKit CoreGraphics
IPARanger_CFLAGS = -fobjc-arc
IPARanger_CODESIGN_FLAGS = -Sentitlements.plist

include $(THEOS_MAKE_PATH)/application.mk
