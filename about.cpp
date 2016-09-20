#include "about.h"
#include "ui_about.h"
#include <QDebug>

About::About(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::About)
{
  ui->setupUi(this);
  qDebug() << "In About constructor";
}

About::~About()
{
  delete ui;
}
