#ifndef DIRECTSOLVER_H
#define DIRECTSOLVER_H

#include <QTabWidget>
#include <TNT/tnt.h>
#include <TNT/jama_lu.h>
#include <vector>
#include "tools.h"
namespace Ui {
  class DirectSolver;
}

class DirectSolver : public QTabWidget
{
  friend class Tools;
  Q_OBJECT
public:
  explicit DirectSolver(QWidget *parent = 0);
  ~DirectSolver();

  void gaussElimination();
  //void swapRows(double (&mat)[n][m], int rowBelow, int rowOnTop);
  void swapRows(vector<vector<double>>& mat, int rowBelow, int rowOnTop);

private slots:
  void on_solveX_clicked();

private:
  Ui::DirectSolver *ui;
  /*
  TNT::Array2D<double> * A;
  TNT::Array2D<double> * B;
  TNT::Array2D<double> * X;
  */
  std::vector< std::vector<double> > A;
  std::vector<double> B;
  std::vector<double> X;
  int n, m;  // row, column
};

#endif // DIRECTSOLVER_H
