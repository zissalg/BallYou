TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += src/main.cpp \
    src/Window.cpp \
    src/GameObject.cpp \
    src/Handler.cpp \
    src/GameType.cpp \
    src/Include.cpp \
    src/TextureManager.cpp

HEADERS += \
    src/Window.h \
    src/GameObject.h \
    src/Handler.h \
    src/GameType.h \
    src/Include.h \
    src/TextureManager.h
