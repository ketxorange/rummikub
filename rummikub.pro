QT += network
TEMPLATE = app
TARGET = rummikub

HEADERS += block.h \
           blockcontainer.h \
           blockgroup.h \
           blockrandom.h \
           board.h \
           client.h \
           mainwindow.h \
           server.h \
           serverconnectionthread.h \
           serverprops.h \
           serverthread.h
FORMS += mainwindow.ui serverprops.ui
SOURCES += block.cpp \
           blockcontainer.cpp \
           blockgroup.cpp \
           blockrandom.cpp \
           board.cpp \
           client.cpp \
           main.cpp \
           mainwindow.cpp \
           server.cpp \
           serverconnectionthread.cpp \
           serverprops.cpp \
           serverthread.cpp
