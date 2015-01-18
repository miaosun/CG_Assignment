#include "linePanel.h"

LinePanel::LinePanel(MainView *glView) : QWidget() {
    this->glView = glView;
    this->string = "";

    init();
}

void LinePanel::init() {
    lPanelLayout = new QGridLayout();
    this->setLayout(lPanelLayout);
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

    QPushButton *startRotationButton = new QPushButton("Start rotation");
    lPanelLayout->addWidget(startRotationButton);

    connect(startRotationButton, SIGNAL(clicked()), this, SLOT(setValues()));

    connect(this, SIGNAL(setValueFinished()), glView, SLOT(startLineRotation()));

    this->hide();
}

void LinePanel::setValues() {
    qDebug() << "Inside setValues() - LinePanel";
    glView->setLine(xValue->value(), yValue->value(), zValue->value());

    emit setValueFinished();
}

void LinePanel::showLineRotationPanel() {
    if(this->isHidden())
        this->show();
    else
        this->hide();
}
