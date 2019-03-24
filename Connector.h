#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QPointer>

#include "CSVFileReader.h"
#include "mainwindow.h"

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(MainWindow* window,
                       CSVFileReader* fileReader,
                       QObject *parent = nullptr);

private:
    void connectObjects();

signals:

public slots:

private:
    QPointer<MainWindow> mainWindow;
    QPointer<CSVFileReader> csvFileReader;
};

#endif // CONNECTOR_H
