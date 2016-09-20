#ifndef UNIVARIATEPROBLEMS_H
#define UNIVARIATEPROBLEMS_H

#include <QTabWidget>
#include "bisectionmethod.h"

namespace Ui {
  class UnivariateProblems;
}

class UnivariateProblems : public QTabWidget
{
  Q_OBJECT

public:
  explicit UnivariateProblems(QWidget *parent = 0);
  ~UnivariateProblems();

private slots:
  void on_radio_special_clicked();
  void on_radio_general_clicked();



  void on_button_solve_clicked();

private:
  Ui::UnivariateProblems *ui;
  BisectionMethod * bisection;
};

#endif // UNIVARIATEPROBLEMS_H
