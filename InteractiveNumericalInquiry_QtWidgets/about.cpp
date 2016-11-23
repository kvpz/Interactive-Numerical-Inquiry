#include "about.h"
#include "ui_about.h"
#include <QDebug>
#include <qwt_text_engine.h> // allows use of MathML
#include <qwt_text.h>
#include <qwt_math.h>
#include <qwt.h>
#include <qwt_mathml_text_engine.h>

About::About(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::About)
{
  ui->setupUi(this);
  qDebug() << "In About constructor";
  QwtText::setTextEngine(QwtText::MathMLText, new QwtMathMLTextEngine);
}

About::~About()
{
  delete ui;
}
