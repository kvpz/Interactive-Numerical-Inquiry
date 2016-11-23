#include "openfile.h"
#include "ui_openfile.h"

OpenNewFile::OpenNewFile(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OpenNewFile)
{
  ui->setupUi(this);

  QString sPath = "C:\\";
  dirModel = new QFileSystemModel(this);
  // To display only directories
  dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
  dirModel->setRootPath(sPath);
  ui->treeView->setModel(dirModel);

  fileModel = new QFileSystemModel(this);
  fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
  fileModel->setRootPath(sPath);
  ui->listView->setModel(fileModel);
}

OpenNewFile::~OpenNewFile()
{
  delete ui;
}

void OpenNewFile::on_treeView_clicked(const QModelIndex &index)
{
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(sPath));

}
