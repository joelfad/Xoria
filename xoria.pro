TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console
CONFIG += warn_on
CONFIG += debug
CONFIG += c++14

unix:INCLUDEPATH += /usr/include/libtcod
LIBS += -ltcod -ltcodxx

SOURCES += \
    src/main.cpp \
    src/tile.cpp \
    src/map.cpp \
    src/game.cpp \

HEADERS += \
    src/tile.h \
    src/constants.h \
    src/map.h \
    src/game.h
