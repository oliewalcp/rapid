QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Core/Conver.cpp \
    Core/DoubleLinkedList.cpp \
    Core/Exception.cpp \
    Core/Matrix.cpp \
    Core/SingleLinkedList.cpp \
    Core/Stack.cpp \
    Core/Vector.cpp \
    Gui/Application.cpp \
    Gui/Frame.cpp \
    Gui/Label.cpp \
    Gui/Widget.cpp \
    Image/ImageBase.cpp \
        main.cpp \
    Core/Memory.cpp

HEADERS += \
    Core/Atomic.h \
    Core/Exception.h \
    Core/Matrix.h \
    Core/Memory.h \
    Core/RapidConfig.h \
    Core/SharedPointer.h \
    Core/Vector.h \
    Core/Stack.h \
    Core/TypeTraits.h \
    Core/Conver.h \
    Core/SingleLinkedList.h \
    Core/Version.h \
    Core/Reflect.h \
    Core/Range.h \
    Core/DoubleLinkedList.h \
    Core/Preoperation.h \
    Gui/Application.h \
    Gui/Frame.h \
    Gui/GuiConfig.h \
    Gui/Label.h \
    Gui/Widget.h \
    Image/ImageBase.h
