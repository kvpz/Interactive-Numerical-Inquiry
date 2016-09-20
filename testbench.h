#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <QWidget>
#include "tools.h"


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
