#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QStringList>
#include "TableModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

signals:
    void setFileName(const QString &filePath);

public slots:
    void setDataList(const QList<QStringList>& list);

private:
    Ui::MainWindow *ui;
    TableModel *model = nullptr;
};

#endif // MAINWINDOW_H
