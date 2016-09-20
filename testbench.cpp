#include "testbench.h"
#include "ui_testbench.h"

TestBench::TestBench(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TestBench)
{
  ui->setupUi(this);
  ui->clock_ticks_value->setText(QString::number(CLOCKS_PER_SEC));
}

TestBench::~TestBench()
{
  delete ui;
}
