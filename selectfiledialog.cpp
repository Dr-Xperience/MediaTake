#include "selectfiledialog.h"
#include "ui_selectfiledialog.h"

SelectFileDialog::SelectFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectFileDialog)
{
    ui->setupUi(this);

    mDirModel=new QFileSystemModel(this);
    mDirModel->setRootPath("/");
    mDirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    QModelIndex vIndex = mDirModel->index("/home");
    ui->lineEditFilePath->setText("/home");

    ui->treeViewFolderExplorer->setModel(mDirModel);
    ui->treeViewFolderExplorer->expand(vIndex);
    ui->treeViewFolderExplorer->scrollTo(vIndex);
    ui->treeViewFolderExplorer->setCurrentIndex(vIndex);
    ui->treeViewFolderExplorer->setColumnWidth(0,200);
//    ui->treeViewFolderExplorer->resizeColumnToContents(0);

}

SelectFileDialog::~SelectFileDialog()
{
    delete ui;
}

void SelectFileDialog::on_treeViewFolderExplorer_pressed(const QModelIndex &index)
{

    ui->lineEditFilePath->setText(mDirModel->fileInfo(index).absoluteFilePath());

}

void SelectFileDialog::on_pushButtonSelect_clicked()
{
    emit selectedPath(ui->lineEditFilePath->text());
    SelectFileDialog::close();
}

void SelectFileDialog::on_pushButtonClose_clicked()
{
    SelectFileDialog::close();
}
