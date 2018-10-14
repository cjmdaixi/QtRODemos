QT += remoteobjects

CONFIG += c++11 console

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp

REPC_SOURCE = ../Reps/filereader.rep

INCLUDEPATH += "$$(BOOST_ROOT)"
LIBS += -L$$(BOOST_ROOT)/lib
## Use only one of these:
LIBS += -lboost_filesystem-vc120-mt-x64-1_68 # using dynamic lib (not sure if you need that "-mt" at the end or not)
#LIBS += $${_BOOST_PATH}/lib/libboost_chrono-mt.a # using static lib

