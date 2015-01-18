#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <math.h>
#include <QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)//, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::init()
{
    QGLFormat format;
    format.setVersion(4,0);
    format.setProfile(QGLFormat::CoreProfile);
    glView = new MainView(format);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(glView);

    QWidget *cPanel = new QWidget(this);
    QHBoxLayout *cPanelLayout = new QHBoxLayout();
    cPanel->setLayout(cPanelLayout);

    lPanel = new LinePanel(glView);

    vPanel = new ViewPanel(glView);

    QPushButton *lRotationButton = new QPushButton("Line Rotation");
    cPanelLayout->addWidget(lRotationButton);
    QObject::connect( lRotationButton, SIGNAL(clicked()), this, SLOT(showLineRotationPanel()) );

    QPushButton *vPositionButton = new QPushButton("View Position");
    cPanelLayout->addWidget(vPositionButton);
    QObject::connect(vPositionButton, SIGNAL(clicked()), this, SLOT(showViewPositionPanel()) );

    QPushButton *defaultViewButton = new QPushButton("Default Position");
    cPanelLayout->addWidget(defaultViewButton);
    QObject::connect(defaultViewButton, SIGNAL(clicked()), glView, SLOT(defaultView()));

    mainLayout->addWidget(cPanel);

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

    mainLayout->addWidget(lPanel);
    mainLayout->addWidget(vPanel);

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(mainLayout);
    this->setWindowTitle("CG Assignment");
}

void MainWindow::showLineRotationPanel() {
    if(!vPanel->isHidden())
        vPanel->hide();

    if(lPanel->isHidden())
        lPanel->show();
    else
        lPanel->hide();

//    vPanel->hide();
//    lPanel->show();
}

void MainWindow::showViewPositionPanel() {
    if(!lPanel->isHidden())
        lPanel->hide();

    if(vPanel->isHidden())
        vPanel->show();
    else
        vPanel->hide();

//    lPanel->hide();
//    vPanel->show();
}
