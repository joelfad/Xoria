TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console
CONFIG += warn_on
CONFIG += debug
CONFIG += c++14

unix:INCLUDEPATH += include
unix:INCLUDEPATH += /usr/include/libtcod
LIBS += -ltcod -ltcodxx

SOURCES += \
    src/main.cpp \
    src/tile.cpp \
    src/map.cpp \
    src/game.cpp \
    src/world.cpp \
    src/tui.cpp \
    src/playscreen.cpp \
    src/mapobject.cpp \
    src/entity.cpp \
    src/player.cpp \
    src/coord.cpp \
    src/monster.cpp \
    src/utility.cpp \
    src/properties.cpp

HEADERS += \
    include/tile.h \
    include/constants.h \
    include/map.h \
    include/game.h \
    include/world.h \
    include/tui.h \
    include/playscreen.h \
    include/mapobject.h \
    include/entity.h \
    include/player.h \
    include/coord.h \
    include/monster.h \
    include/utility.h \
    include/properties.h
