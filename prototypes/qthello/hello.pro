CONFIG  += qt debug
TEMPLATE = app
VERSION = 0.1.1
TARGET = hello
QT += gui widgets
DEFINES += UNICODE QT_THREAD_SUPPORT QT_CORE_LIB QT_GUI_LIB

SOURCES  = \
    main.cpp

# Mac OS X-specific:
mac {
  DEFINES += MACOSX
  QMAKE_CXXFLAGS += -D__MACOSX_CORE__
  QMAKE_CXXFLAGS += -stdlib=libstdc++
  # CONFIG-=app_bundle
}

