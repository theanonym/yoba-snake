TARGET = yoba-snake

CONFIG -= qt

INCLUDEPATH = /usr/include/ /usr/local/include/ src
LIBS += -lsfml-system -lsfml-graphics -lsfml-window

QMAKE_CXX = g++
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/engine/baseapplication.cpp \
    src/engine/basescene.cpp \
    src/engine/resources.cpp \
    src/game/world.cpp \
    src/game/mainmenu.cpp \
    src/game/main.cpp \
    src/game/game.cpp \
    src/game/application.cpp \
    src/game/snake.cpp

HEADERS += \
    src/engine/baseapplication.hpp \
    src/engine/basescene.hpp \
    src/engine/common.hpp \
    src/engine/random.hpp \
    src/engine/resources.hpp \
    src/engine/singleton.hpp \
    src/game/world.hpp \
    src/game/state.hpp \
    src/game/mainmenu.hpp \
    src/game/game.hpp \
    src/game/application.hpp \
    src/game/snake.hpp

