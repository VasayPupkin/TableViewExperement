#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QString>

#include "CSVFileReader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setVisible(false);
    model = new TableModel();
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/home/oleg", tr("All Files (*.*)"));
    ui->lineEdit->setText(fileName);
    emit setFileName(fileName);
}

void MainWindow::setDataList(const QList<QStringList> &list)
{
    model->setDataList(list);
    ui->tableView->setVisible(true);
    ui->tableView->setModel(model);
}
