#-------------------------------------------------
#
# Project created by QtCreator 2016-09-01T12:57:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InteractiveNumericalInquiry
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    openfile.cpp \
    testbench.cpp \
    bisectionmethod.cpp \
    univariateproblems.cpp \
    tools.cpp \
    directsolver.cpp

HEADERS  += mainwindow.h \
    about.h \
    openfile.h \
    testbench.h \
    bisectionmethod.h \
    univariateproblems.h \
    tools.h \
    directsolver.h

# At compile time (by uic), forms are converted to c++ code (see Debug folder)
FORMS    += \
    mainwindow.ui \
    about.ui \
    openfile.ui \
    testbench.ui \
    univariateproblems.ui \
    directsolver.ui

#id ICON
#DISTFILES += \
#    IntNumInq.ico

#RESOURCES += \
#    resources.qrc

# To give the main window an icon at the top left.
win32:RC_ICONS = INI2.ico # 16x16 icon
#win32:RC_ICONS = INI.ico # INI.ico is 32x32

#DISTFILES += \
#    README.md

#CONFIG += qwt


#INCLUDEPATH += $$PWD/../
#DEPENDPATH += $$PWD/../

#DEFINES += ADD_
#DEFINES += HAVE_LAPACK_CONFIG_H
#DEFINES += LAPACK_COMPLEX_STRUCTURE
###########


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD\..\lib\ -lliblapacke
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD\..\lib\ -lliblapack
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD\..\lib\ -llibtmglib
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD\..\lib\ -llibblas
#INCLUDEPATH += $$PWD\..\include
#DEPENDPATH += $$PWD\..\include

#LIB += \
#    -LC:\MinGw\bin\ -llibgfortran-3 \
#    -llibgcc_s_dw2-1

# adding libtmglib.dll will cause issues. It's only used for testing LAPACK.
LIBS += \
    -L$$PWD\..\ -lliblapacke \
    -lliblapack \
#    -llibtmglib \
    -llibblas

INCLUDEPATH += $$PWD/../include \
               $$PWD/mycpp \
               $$PWD/mytcpp \
               $$PWD/mySparse
DEPENDPATH += $$PWD/../include


DISTFILES += \
    README.md


