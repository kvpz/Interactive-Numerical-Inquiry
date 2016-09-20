#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <QWidget>
//#include <lapacke.h>
#include "tools.h"
#include "vector.h"
#include "matrix.h"
#include "matrix_util.h"

#include "sparse.h"
#include "sparse_util.h"

// in lieu of makefile
//#include "xstring.cpp"
//#include "primes.cpp"
//#include "bitvect.cpp"
//#include "hashfunctions.cpp"

namespace Ui {
  class TestBench;
}


class TestBench : public QWidget
{
  Q_OBJECT

public:
  explicit TestBench(QWidget *parent = 0);
  ~TestBench();

private slots:

private:
  Ui::TestBench *ui;
};

#endif // TESTBENCH_H
