#include "tools.h"
#include <QDebug>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

Tools::Tools()
{

}

Tools::~Tools()
{

}

void Tools::readMatrix(vector< vector<double> >& m, QString input)
{
  int i = 0;
  foreach(QString row, input.split("\n"))
  {
    row = row.trimmed();
    if(row == 0) // in case there is blank lines below matrix entries.
      continue;
    foreach(QString val, row.split(" "))
    {
      //val = val.trimmed();
      int j = 0;
      bool isNumber = true;
      double entry = val.toDouble(&isNumber);
      if(isNumber)
      {
        m[i][j] = entry;
        qDebug() << m[i][j] << " ";
      }
      else
      {
        if(val != " " || val != "\n")
        {
          qDebug() << "ERROR: Matrix entry is nonnumeric.";
          return;
        }
      }
      ++j;
    }
    qDebug() << " \n";
    ++i;
  }

  outputMatrix(m);
}

void Tools::getDimensions(QString m, int& rowCount, int& colCount)
{
  rowCount = 0;
  colCount = 0;
  foreach(QString row, m.split("\n"))
  {
    if(row.trimmed() != 0)
      ++rowCount;
    if(colCount != 0) continue;
    foreach(QString col, row.split(" "))
    {
      bool isNumeric = false;
      col.toDouble(&isNumeric);
      if(isNumeric)
        ++colCount;
    }

  }
}

bool Tools::isSquare(const int& row, const int& col)
{
  if(row == col)
    return true;
  else
    return false;
}

void Tools::outputMatrix(std::vector< std::vector<double> > m)
{
  
/*
  auto ritr = m.begin();
  auto citr = ritr[0];//m[0].begin();
  for(; ritr != m.end(); ++ritr)
  {
    for(; citr != ritr->end(); ++citr)
    {
      qDebug() << *citr << " ";
    }
  }
  */
}

void Tools::startTimer()
{
/*
  start = time(NULL);
  const struct tm *tm;
  tm = localtime(&start);
  static char buffer[40];
  strftime(buffer, 40, "%d %B %Y %I:%M:%S %p", tm);
  qDebug() << "Start time: " << buffer;
*/
}

void Tools::stopTimer()
{
/*
  stop = time(NULL);
  const struct tm *tm;
  tm = localtime(&stop);
  static char buffer[40];
  strftime(buffer, 40, "%d %B %Y %I:%M:%S %p", tm);
  qDebug() << "End time: " << buffer;
  */
}
