#include "mainwindow.h"
#include <QApplication> // for GUI applications
#include <QDebug>

#include <stdlib.h>
#include <stdio.h>
/******************************************************/
/* This will prevent errors when compiling with MSVC **/
#include <complex>
#define lapack_complex_float std::complex<float>
#define lapack_complex_double std::complex<double>

/******************************************************/
#include "tools.h"

int main(int argc, char *argv[])
{
    //Tools t;
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}

