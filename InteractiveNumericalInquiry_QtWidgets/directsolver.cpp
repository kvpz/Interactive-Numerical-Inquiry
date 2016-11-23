#include "directsolver.h"
#include "ui_directsolver.h"
#include <QDebug>
#include "tools.h"
#include <cmath>
using namespace std;

DirectSolver::DirectSolver(QWidget *parent) :
  QTabWidget(parent),
  ui(new Ui::DirectSolver)//, n(3), m(4)
{
  ui->setupUi(this);
  qDebug() << "In Direct Solver constructor";
  /*
  int DOF=3;
  TNT::Array2D<double> A(DOF,DOF,0.0);
  TNT::Array2D<double> B(DOF,1,0.0);
  TNT::Array2D<double> X(DOF,1,0.0);
  A[0][0]=0.0;
  A[0][1]=1.0;
  A[0][2]=-3.0;
  A[1][0]=1.0;
  A[1][1]=-1.0;
  A[1][2]=1.0;
  A[2][0]=1.0;
  A[2][1]=0.0;
  A[2][2]=-1.0;

  B[0][0]=4.0;
  B[1][0]=6.0;
  B[2][0]=2.0;

  JAMA::LU<double> decompA(A);
  X = decompA.solve(B);

 qDebug() << "X=" << X[0][0] << ' ' << X[1][0] << ' ' << X[2][0] << '\n';
 */
 //A.resize(5, vector<double>(5));


  //gaussElimination();
}

DirectSolver::~DirectSolver()
{
  delete ui;
}

/**** Solvers ****/
void DirectSolver::gaussElimination()
{
  Tools::startTimer();
  qDebug() << "RUNNING GAUSS!!!";
  //const int n = 3, m = 4;
  /*
   *
   * // test
  double matrix[n][m] = /*{ { 4, 1, 2, 9 },
                        { 7, 4, -1, -5 },
                        { 10, 10, -3, -9 } };*/
          /*{ { 4, -1, 1, 8 },
            { 2, 5, 2, 3 },
            { 1, 2, 4, 11 } };
                        /*{ { 2, -1, 0, 1 },
                      {-1, 2, -1, 0 },
                      { 0, -1, 2, 1 }};
                        */

  
  double largestValueInColumn = 0; //largest pivot value for a swap
  int rowWithLargestPivot = 0; //collects value of row to swap
  bool swap = false; //true if swapping condition met(found larger coefficient in column below pivot)
  double multiple = 0; //=matrix[z][i]/matrix[i][i], z != 0 used during elimination

  /*
  STEP 1

  */
  for (int i = 0; i < n-1; i++)    //This loops on the columns
  {

    rowWithLargestPivot = 0;	 //stores row location of largest pivot point in column  (pg. 373, Pivoting strategies)
    largestValueInColumn = 0;         //stores largest column value to compare with others

    /*STEP 2*/
    //search column for largest value in order to know what row to swap
    for (int p = i; p < n; p++) //p: number of rows
    {
      if (fabs(A[p][i]) >= fabs(A[i][i])) //find larger coefficient in the column than current pivot
      {
        //check if larger than the previous large value found
        if (fabs(A[p][i]) > largestValueInColumn)
        {
          largestValueInColumn = A[p][i]; //collects largest column value to compare to others
          rowWithLargestPivot = p; //row with largest potential pivot
          swap = true; //must swap when a larger number than current pivot is found
          multiple = A[p][i] / A[i][i]; //where p>i
        }
      }
    }//for loop 2

    if (largestValueInColumn == 0)
    {
      ui->status_text->setHtml("<body style=\" font-size:8pt; font-weight:400; color:green;\">Pivot point is 0. Algorithm terminated. </body>");
      //qDebug() << "Pivot point is 0. End of algorithm";
      Tools::stopTimer();
      
      return;
    }

    /*STEP 3*/
    //For increased numerical stability largest possible pivot is used.
    if (swap == true && rowWithLargestPivot!=i) //don't swap if current pivot is largest value in column
    {
      swapRows(A, rowWithLargestPivot,i);
      swap = false; //reset
    }

    if (rowWithLargestPivot == i) //assign row immediately below current pivot if no larger coefficient in column was found
        rowWithLargestPivot = i+1;

    /*STEP 4*/
    for (int z = rowWithLargestPivot; z < n; z++)
    {
      /*STEP 5*/
      multiple = A[z][i] / A[i][i]; //used to multiply through row that will eliminate one below

      /*STEP 6*/
      for (int j = 0; j < m; j++) //This loops through a row
      {
        A[z][j] = A[z][j] - multiple * A[i][j]; //elimination/ change of coefficients
        //printMatrix(matrix);

      }

    }//outer for, for loop 1
  }

    if (A[n - 1][n - 1] == 0)
    {
      QString message = "<body style=\" font-size:8pt; font-weight:400; color:red;\">No solution.\n Failure. </body>";
      ui->status_text->setHtml(message);
      qDebug() << "no solution";
    }

    X = vector<double>(m - 1); //x values to be found
    double sum; //collects sum of product with existing x values and their coefficients
    X[n-1] = A[n - 1][m - 1] / A[n - 1][n - 1];//value of last x (x[n-1])

    for (int i = n - 2; i >= 0; i--)
    { //backward substitution
      sum = 0.0;
      for (int j = i + 1; j < n; j++)
      {
        sum += A[i][j] * X[j]; //sum of rest of equation when other x are plugged in
      }
      X[i] = (A[i][m - 1] - sum) / A[i][i];
    }

    // Success
    auto xitr = X.begin();
    ui->xresult->setText("(");
    for(; xitr != X.end(); ++xitr)
    {
      qDebug() << *xitr << " ";
      ui->xresult->append(QString::number(*xitr));
      if((xitr+1) != X.end())
        ui->xresult->append(", ");
    }
    ui->xresult->append(")");
          QString message = "<body style=\" font-size:8pt; font-weight:400; color:red;\">No solution.\n Failure. </body>";
      ui->xresult->setHtml(message);
      
  Tools::stopTimer();
}
void DirectSolver::swapRows(vector<vector<double>>& mat, int rowBelow, int rowOnTop)
{
  double temp;
  for (int c = 0; c < m; c++)
  {
    temp = mat[rowBelow][c];
    mat[rowBelow][c] = mat[rowOnTop][c];
    mat[rowOnTop][c] = temp;
  }
}

void DirectSolver::on_solveX_clicked()
{
    Tools::getDimensions(ui->text_A->toPlainText(), n, m);
    qDebug() << "n,m= " << n << ' ' << m;
    A = vector< vector<double> >(n, vector<double>(m));
    Tools::readMatrix(A, ui->text_A->toPlainText());
    gaussElimination();
}
