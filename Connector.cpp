#include "Connector.h"

Connector::Connector(MainWindow* window,
                     CSVFileReader* fileReader,
                     QObject *parent) :
    QObject(parent)
{
    mainWindow = window;
    csvFileReader = fileReader;
    connectObjects();
}

void Connector::connectObjects()
{
    connect(mainWindow.data(),SIGNAL(setFileName(QString)),
            csvFileReader.data(), SLOT(fileParse(QString)));
    connect(csvFileReader.data(),SIGNAL(setDataList(QList<QStringList>)),
            mainWindow.data(), SLOT(setDataList(QList<QStringList>)));
}

