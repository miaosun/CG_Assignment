#include <QApplication>
#include <math.h>
#include "mainwindow.h"

#define RADPERDEG 0.0174533

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // The main window
    MainWindow win;

    win.show();

    return app.exec();
}
