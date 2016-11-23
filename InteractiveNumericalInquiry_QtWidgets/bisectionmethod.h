/*
 * Bisection method (aka Binary-search method)
 * This method is used to get a numerical approximation to what is called
 * the root-finding problem (finding the root, or solution, of an equation
 * of the form f(x) = 0).
 * Assume f is a continuous function defined on [a,b], with f(a) and f(b)
 * of opposite sign. The Intermediate Value Theorem implies that a number p
 * exists in (a,b) with f(p)=0. For simplicity, assume interval only has
 * one root.
 *
 * -----------------------
 * Variable Used
 * -----------------------
 * x_max = largest value of b(end of interval)
 * TOL = tolerance
 * a = first endpoint
 * b = last endpoint
 * solution = initially midpoint of [a,b]
 * maxIterations = max number of iterations
 *
 *
 * In textbooks, tolerance, TOL, may also be referred as greek letter epsilon.
 * The midpoint may also be referred to as 'p'.
 *
 */
#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include <QWidget>
#include <QtWidgets>

class BisectionMethod : public QWidget
{

  Q_OBJECT
public:
  // pointer to special functions(single variable equations)
  typedef double (BisectionMethod::*funcPointer)(double x);

  explicit BisectionMethod(QWidget *parent = 0);

  // special (hard coded) equations
  double func_special_1(double x);
  double func_special_2(double x);

  bool terminate1(double a, double b, char c = 1) const;

  bool IVT(funcPointer func, const double a, const double b);
  bool checkIfSolvable(funcPointer func);

  double bisection_method_special(funcPointer func, char endCriteria);
  void bisection_method(double a, double b, double epsilon = 0.0001);
  void weighted_bisection_method(double a, double b, double p);

  // modifier functions
  void setLeftBound(double x)           { a = x;}
  void setRightBound(double x)          { b = x;}
  void setTolerance(double x)           { TOL = x; }
  void setMaxIterations(unsigned int x) { maxIterations = x; }

  // accessor functions
  double getLeftBound()   const           { return a; }
  double getRightBound()  const           { return b; }
  double getTolerance()   const           { return TOL; }
  unsigned int getMaxIterations() const   { return maxIterations; }

signals:

public slots:

private:
  double a, b, TOL, solution;
  int maxIterations;
};

#endif // BISECTIONMETHOD_H
