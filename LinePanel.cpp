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
    angleValue = new QDoubleSpinBox();
    angleValue->setRange(-36000.0, 36000.0);
    lPanelLayout->addWidget(angleValue, 0, 1);
    QLabel *xLabel = new QLabel("x value");
    lPanelLayout->addWidget(xLabel, 0, 2);
    xValue = new QDoubleSpinBox();
    xValue->setRange(-100.0, 100.0);
    xValue->setSingleStep(0.5);
    lPanelLayout->addWidget(xValue, 0, 3);
    QLabel *yLabel = new QLabel("y value");
    lPanelLayout->addWidget(yLabel, 1, 0, 1, 1);
    yValue = new QDoubleSpinBox();
    yValue->setRange(-100.0, 100.0);
    yValue->setSingleStep(0.5);
    lPanelLayout->addWidget(yValue, 1, 1, 1, 1);
    QLabel *zLabel = new QLabel("z value");
    lPanelLayout->addWidget(zLabel, 1, 2, 1, 1);
    zValue = new QDoubleSpinBox();
    zValue->setRange(-100.0, 100.0);
    zValue->setSingleStep(0.5);
    lPanelLayout->addWidget(zValue, 1, 3, 1, 1);

    QPushButton *applyButton = new QPushButton("Apply");
    lPanelLayout->addWidget(applyButton);

    QPushButton *startRotationButton = new QPushButton("Start rotation");
    lPanelLayout->addWidget(startRotationButton);

    //float t = edt1->text().toFloat();

    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);
    //QObject::connect(startRotationButton, SIGNAL(clicked()), glView, SLOT(startLineRotation()));

    signalMapper = new QSignalMapper(startRotationButton);

    //connect(startRotationButton, SIGNAL(clicked()), this, SLOT(showLineRotationPanel()));


    connect(applyButton, SIGNAL(clicked()), this, SLOT(setString()));

    connect(startRotationButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    //QString string = angleLine->text()+" "+xLine->text()+" "+yLine->text()+" "+zLine->text();
    //qDebug() << string;

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
    this->string = angleValue->text()+" "+xValue->text()+" "+yValue->text()+" "+zValue->text();
    qDebug() << this->string;
    emit setStringFinished();
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
