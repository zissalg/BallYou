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
    src/TextureManager.cpp \
    src/Player.cpp \
    src/KeyInput.cpp \
    src/BasicEnemy.cpp \
    src/Detector.cpp \
    src/Statistics.cpp \
    src/Text.cpp \
    src/FontManager.cpp \
    src/Wave.cpp

HEADERS += \
    src/Window.h \
    src/GameObject.h \
    src/Handler.h \
    src/GameType.h \
    src/Include.h \
    src/TextureManager.h \
    src/Player.h \
    src/KeyInput.h \
    src/BasicEnemy.h \
    src/Detector.h \
    src/Statistics.h \
    src/Text.h \
    src/FontManager.h \
    src/Wave.h
