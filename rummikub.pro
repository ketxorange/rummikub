# -------------------------------------------------
# Project created by QtCreator 2009-02-24T19:04:49
# -------------------------------------------------
QT += network
TARGET = rummikub
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    client.cpp \
    server.cpp \
    board.cpp \
    blockgroup.cpp \
    block.cpp \
    serverconnectionthread.cpp \
    serverthread.cpp \
    serverprops.cpp
HEADERS += mainwindow.h \
    client.h \
    server.h \
    board.h \
    blockgroup.h \
    block.h \
    serverconnectionthread.h \
    serverthread.h \
    serverprops.h
FORMS += mainwindow.ui \
    serverprops.ui
