/****************************************************************************
    Media Take : A Qt and GStreamer Based cross platform Media Player for PC
    Copyright (C) 2013  Anubhav Arun

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*****************************************************************************/

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
