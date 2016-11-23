#include "openfile.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>
#include "tools.h"

//https://en.wikipedia.org/wiki/Visual_C%2B%2B
//enum compilers {};

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex(0);

  QString sinfo("built on " + QSysInfo::prettyProductName());
  sinfo += " " + QSysInfo::buildAbi();
  ui->label_main->setText(sinfo);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
  // modal window
  //About about;
  //about.setModal(true);
  //about.exec();

  // modeless window
  about = new About(this);
  about->show();
}



void MainWindow::on_actionOpen_input_file_triggered()
{
    //qDebug() << "Going to open a new file";
    OpenNewFile ofw;
    ofw.setModal(true);
    ofw.exec();
}


void MainWindow::on_Testbench_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_SingleVarSol_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backToMainButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_button_direct_solver_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}
