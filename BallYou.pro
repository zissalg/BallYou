TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += src/main.cpp \
    src/BasicEnemy.cpp \
    src/Detector.cpp \
    src/FontManager.cpp \
    src/GameObject.cpp \
    src/GameType.cpp \
    src/Handler.cpp \
    src/Include.cpp \
    src/KeyInput.cpp \
    src/MouseInput.cpp \
    src/Player.cpp \
    src/TextureManager.cpp \
    src/Window.cpp \
    src/Widgets/Button.cpp \
    src/Widgets/GameWidget.cpp \
    src/Widgets/Menu.cpp \
    src/Widgets/Text.cpp

HEADERS += \
    src/BasicEnemy.h \
    src/Detector.h \
    src/FontManager.h \
    src/GameObject.h \
    src/GameType.h \
    src/Handler.h \
    src/Include.h \
    src/KeyInput.h \
    src/MouseInput.h \
    src/Player.h \
    src/TextureManager.h \
    src/Window.h \
    src/Widgets/Button.h \
    src/Widgets/GameWidget.h \
    src/Widgets/Menu.h \
    src/Widgets/Text.h
