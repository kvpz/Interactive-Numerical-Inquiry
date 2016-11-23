#ifndef TOOLS_H
#define TOOLS_H

#include <ctime>
#include <cmath>
#include <QSysInfo>
#include <TNT/tnt.h>
#include <QWidget>
#include <QTextEdit>
#include <vector>

class Tools
{

public:
  Tools();
  ~Tools();
  // determine if f(x) <,==,> to 1,0,-1
  short int signum(double x);

  // Tools for matrices
  static void readMatrix(vector< vector<double> >& m, QString);
  static void outputMatrix(std::vector< std::vector<double> > m);
  static void getDimensions(QString, int& r, int& c);
  static bool isSquare(const int& r, const int& c);
  static void startTimer();
  static void stopTimer();
  
  time_t start;
  time_t stop;
};

#endif // TOOLS_H
