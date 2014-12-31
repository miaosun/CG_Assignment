#include "linePanel.h"

LinePanel::LinePanel(MainView *glView, const QGLFormat &format, QWidget *parent) : QGLWidget(format, parent) {
    this->glView = glView;
    lPanel = new QWidget(parent);
    this->string = "";
}

void LinePanel::init() {
    lPanelLayout = new QGridLayout();
    lPanel->setLayout(lPanelLayout);
    lPanelLayout->setSpacing(20);
    QLabel *angle = new QLabel("Angle");
    lPanelLayout->addWidget(angle, 0, 0);
    angleLine = new QLineEdit();
    lPanelLayout->addWidget(angleLine, 0, 1);
    QLabel *xValue = new QLabel("x value");
    lPanelLayout->addWidget(xValue, 0, 2);
    xLine = new QLineEdit();
    lPanelLayout->addWidget(xLine, 0, 3);
    QLabel *yValue = new QLabel("y value");
    lPanelLayout->addWidget(yValue, 1, 0, 1, 1);
    yLine = new QLineEdit();
    lPanelLayout->addWidget(yLine, 1, 1, 1, 1);
    QLabel *zValue = new QLabel("z value");
    lPanelLayout->addWidget(zValue, 1, 2, 1, 1);
    zLine = new QLineEdit();
    lPanelLayout->addWidget(zLine, 1, 3, 1, 1);

    QPushButton *startRotationButton = new QPushButton("Start rotation");
    lPanelLayout->addWidget(startRotationButton);

    //float t = edt1->text().toFloat();

    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);
    //QObject::connect(startRotationButton, SIGNAL(clicked()), glView, SLOT(startLineRotation()));

    signalMapper = new QSignalMapper(startRotationButton);

    //connect(startRotationButton, SIGNAL(clicked()), this, SLOT(showLineRotationPanel()));


    connect(startRotationButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    //QString string = angleLine->text()+" "+xLine->text()+" "+yLine->text()+" "+zLine->text();
    //qDebug() << string;

    connect(startRotationButton, SIGNAL(clicked()), this, SLOT(setString()));

    signalMapper->setMapping(startRotationButton, getString());
    connect(signalMapper, SIGNAL(mapped(QString)), glView, SLOT(startLineRotation(QString)));

    //connect(signalMapper, SIGNAL(mapped(QString)),startRotationButton, SIGNAL(clicked()));
    //connect(startRotationButton, SIGNAL(clicked()),glView, SLOT(startLineRotation(QString)));
    //connect(signalMapper, SIGNAL(mapped(QString)),glView, SLOT(startLineRotation(QString)));

    //mainLayout->addWidget(lPanel);
    lPanel->hide();
}

QString LinePanel::getString() {
    qDebug() << "Inside getString()" << this->string;
    return this->string;
}

void LinePanel::setString() {
    qDebug() << "Inside setString()";
    this->string = angleLine->text()+" "+xLine->text()+" "+yLine->text()+" "+zLine->text();
    qDebug() << this->string;
}

void LinePanel::showLineRotationPanel() {
    qDebug() << "Inside showLineRotationPanel()";
    if(lPanel->isHidden())
        lPanel->show();
    else
        lPanel->hide();
}

QWidget* LinePanel::getLPanel() {
    return this->lPanel;
}
