#include "bisectionmethod.h"
#include <QDebug>

BisectionMethod::BisectionMethod(QWidget *parent) : QWidget(parent)
{
  //bisection_method_special(&BisectionMethod::func_special_1);
  //bisection_method_special(&BisectionMethod::func_special_1);
  if(parent != NULL)
  {
    qDebug() << parent->objectName();
    //parent->
  }
}

double BisectionMethod::func_special_1(double x)
{
  return x*x*x + 4*x*x - 10;
}

/*
 * Different stopping criteria, which are selected by parameter c.
 * f(x_i)==0 is always a stopping critera as seen in the bisection method.
 */
bool BisectionMethod::terminate1(double a, double b, char c) const
{
  if(c == 1)
  {

  }
  else if(c == 2)
  {

  }
  else
  {
    return (b-a)/2.0 < TOL;
  }
}

inline double BisectionMethod::func_special_2(double x)
{
  return x*x;
}

void BisectionMethod::bisection_method(double a, double b, double epsilon)
{


}

/*
 * Intermediate Value Theorem. It is used to check whether there is a solution
 * in the given interval. This will be useful for the user because if they
 * don't get a solution after the bisection method terminates, and this
 * theorem says there should be a solution, then it may be that they did not
 * set an appropriate maximum number of iterations.
 */
bool BisectionMethod::IVT(funcPointer func, const double a, const double b)
{
  double f_a = (this->*func)(a);
  double f_b = (this->*func)(b);
  if(f_a <= 0 && f_b >= 0) return true;
  else return false;
}

/*
 * The following criteria are required for the Bisection method to work.
 * f_a0 * f_b0 < 0
 *
 */
bool BisectionMethod::checkIfSolvable(funcPointer func)
{
  // f_a*f_b < 0
  return true;
}

double BisectionMethod::bisection_method_special(funcPointer func, char c)
{
  unsigned int i = 0;
  double fval; // value of function
  solution = 0;
  while(i < maxIterations)
  {
    solution = a + (b-a)/2.0; // (a + b)/2.0;
    fval = (this->*func)(solution);

    // Stopping criteria
    if( (fval == 0.0) || terminate1(a,b,c))//((b-a)/2.0 < TOL) )
    {
      qDebug() << "Bisection method terminated successfully: ";
      return solution;
    }
    ++i;

    if ( (this->*func)(a)*fval > 0.0 ) a = solution;
    else b = solution;
  }

  qDebug() << "Bisection method failed";
  return NULL;
}

