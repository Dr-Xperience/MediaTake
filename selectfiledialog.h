#ifndef SELECTFILEDIALOG_H
#define SELECTFILEDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFileSystemModel>

namespace Ui {
class SelectFileDialog;
}

class SelectFileDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectFileDialog(QWidget *parent = 0);
    ~SelectFileDialog();

signals:
    void selectedPath(QString);
private slots:
    void on_treeViewFolderExplorer_pressed(const QModelIndex &index);

    void on_pushButtonSelect_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::SelectFileDialog *ui;
    QFileSystemModel *mDirModel;
};

#endif // SELECTFILEDIALOG_H
