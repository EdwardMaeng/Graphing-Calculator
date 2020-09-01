TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"..\..\SFML-2.0\lib"
LIBS += -L"..\..\SFML-2.0\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "..\..\SFML-2.0\include"
DEPENDPATH += "..\..\SFML-2.0\include"

SOURCES += \
        animate.cpp \
        evaluate.cpp \
        function.cpp \
        lparen.cpp \
        main.cpp \
        number.cpp \
        operator.cpp \
        rparen.cpp \
        rpn.cpp \
        shunting_yard.cpp \
        sidebar.cpp \
        system.cpp \
        token.cpp \
        transform.cpp \
        variable.cpp

HEADERS += \
    ../../Iterated_List/Iterated_List/Iterated_List.h \
    ../../Linked_List/linked_list_functions.h \
    animate.h \
    constants.h \
    evaluate.h \
    function.h \
    lparen.h \
    number.h \
    operator.h \
    rparen.h \
    rpn.h \
    shunting_yard.h \
    sidebar.h \
    stack_and_queue.h \
    system.h \
    token.h \
    transform.h \
    variable.h \
    z_work_report.h
