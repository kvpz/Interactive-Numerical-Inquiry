#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
  class OpenNewFile;
}

class OpenNewFile : public QDialog
{
  Q_OBJECT

public:
  explicit OpenNewFile(QWidget *parent = 0);
  ~OpenNewFile();

private slots:
  void on_treeView_clicked(const QModelIndex &index);

private:
  Ui::OpenNewFile *ui;
  QFileSystemModel *dirModel;
  QFileSystemModel *fileModel;
};

#endif // OPENFILE_H
