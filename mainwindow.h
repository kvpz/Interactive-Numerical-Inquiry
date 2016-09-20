#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "about.h" // for modal window
#include "openfile.h"
#include "testbench.h"
#include "univariateproblems.h"
#include "directsolver.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_actionAbout_triggered();
  void on_actionOpen_input_file_triggered();

  void on_Testbench_clicked();
  void on_SingleVarSol_clicked();
  void on_button_direct_solver_clicked();

  void on_backToMainButton_clicked();



private:
  Ui::MainWindow *ui;
  About *about;  // for a modal window
  TestBench * testbench;
  UnivariateProblems * singleVarWidget;
  DirectSolver * directSolver;
  QStackedWidget * widgetStack;

  //OpenFile *openFileWindow;
};

#endif // MAINWINDOW_H
