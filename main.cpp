#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <math.h>
#include <QDebug>

#include "mainwindow.h"

#define RADPERDEG 0.0174533

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // The main window
    //QWidget win;
    MainWindow win;
/*
    QGLFormat format;
    format.setVersion(4,0);
    format.setProfile(QGLFormat::CoreProfile);
    MainView *glView = new MainView(format);

    QVBoxLayout *mainLayout = new QVBoxLayout(&win);
    mainLayout->addWidget(glView);

    QWidget *cPanel = new QWidget(&win);
    QHBoxLayout *cPanelLayout = new QHBoxLayout();
    cPanel->setLayout(cPanelLayout);

    LinePanel *lPanel = new LinePanel(glView, format);
    lPanel->init();

    ViewPanel *vPanel = new ViewPanel(glView, format);
    vPanel->init();

    QPushButton *lRotationButton = new QPushButton("Line Rotation");
    cPanelLayout->addWidget(lRotationButton);
    QObject::connect( lRotationButton, SIGNAL(clicked()), lPanel, SLOT(showLineRotationPanel()) );

    QPushButton *vPositionButton = new QPushButton("View Position");
    cPanelLayout->addWidget(vPositionButton);
    QObject::connect(vPositionButton, SIGNAL(clicked()), vPanel, SLOT(showViewPositionPanel()) );

    QPushButton *defaultViewButton = new QPushButton("Default Position");
    cPanelLayout->addWidget(defaultViewButton);
    QObject::connect(defaultViewButton, SIGNAL(clicked()), glView, SLOT(defaultView()));

    mainLayout->addWidget(cPanel);
    //drawAxes(30.0);
    //
    // line seperator
    //
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    mainLayout->addWidget(line);
    //
    // end line separator
    //

    mainLayout->addWidget(lPanel->getLPanel());
    mainLayout->addWidget(vPanel->getVPanel());


    win.setLayout(mainLayout);
    win.setWindowTitle("CG Assignment");
*/
    win.show();

    return app.exec();
}
