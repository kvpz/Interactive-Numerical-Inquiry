#include "univariateproblems.h"
#include "ui_univariateproblems.h"
#include <QDebug>

UnivariateProblems::UnivariateProblems(QWidget *parent) :
  QTabWidget(parent),
  ui(new Ui::UnivariateProblems)
{
  ui->setupUi(this);
  ui->specialRoutines_cbox_bisection->setEditable(false);
  ui->specialRoutines_cbox_bisection->addItem("x^3 + 4x^2 - 10");

  ui->radio_special->setChecked(true);

  // the first special function will be placed in f(x) box
  ui->f_x_input->setText(ui->specialRoutines_cbox_bisection->itemText(0));
  bisection = new BisectionMethod(this);
  bisection->setLeftBound(1);
  bisection->setRightBound(2);
  bisection->setTolerance(0.0001);
  bisection->setMaxIterations(100000);
  ui->a_input->setText( QString::number( bisection->getLeftBound() ));
  ui->b_input->setText( QString::number( bisection->getRightBound() ));
  ui->tol_input->setText( QString::number( bisection->getTolerance() ));
  ui->iter_lineEdit->setText( QString::number (bisection->getMaxIterations() ));
}

UnivariateProblems::~UnivariateProblems()
{
  delete ui;
}

void UnivariateProblems::on_radio_special_clicked()
{
  qDebug() << "Special radio button is selected";
  ui->f_x_input->setText(ui->specialRoutines_cbox_bisection->itemText(0));
}

void UnivariateProblems::on_radio_general_clicked()
{
    ui->f_x_input->clear();
}

void UnivariateProblems::on_button_solve_clicked()
{
    if(ui->radio_special->isChecked())
    {
      double a = ui->a_input->text().toDouble();
      double b = ui->b_input->text().toDouble();
      double tolerance = ui->tol_input->text().toDouble();
      double maxitr = ui->iter_lineEdit->text().toDouble();

      bisection->setLeftBound(a);
      bisection->setRightBound(b);
      bisection->setTolerance(tolerance);
      bisection->setMaxIterations(maxitr);
      double result = bisection->bisection_method_special(&BisectionMethod::func_special_1, 1);

      if(result == NULL)
      {
        ui->solution_lineEdit->setText("NULL");
      }
      else
      {
        qDebug() << "Special bisection solution: " << result;
        ui->solution_lineEdit->setText(QString::number(result));
      }

    }
}
