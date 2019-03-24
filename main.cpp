#include "mainwindow.h"
#include <QApplication>

#include "CSVFileReader.h"
#include "Connector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CSVFileReader fileReader;
    Connector connector(&w, &fileReader);

    w.show();

    return a.exec();
}
