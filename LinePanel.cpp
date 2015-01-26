#include "linePanel.h"

LinePanel::LinePanel(MainView *glView) : QWidget() {
    this->glView = glView;

    init();
}

void LinePanel::init() {
    lPanelLayout = new QGridLayout();
    this->setLayout(lPanelLayout);
    lPanelLayout->setSpacing(20);
    QLabel *angle = new QLabel("Angle");
    lPanelLayout->addWidget(angle, 2, 0);
    angleValue = new QDoubleSpinBox();
    angleValue->setRange(-360.0, 360.0);
    lPanelLayout->addWidget(angleValue, 2, 1);
    QLabel *bXLabel = new QLabel("bx value");
    lPanelLayout->addWidget(bXLabel, 0, 0);
    bXValue = new QDoubleSpinBox();
    bXValue->setRange(-100.0, 100.0);
    bXValue->setSingleStep(0.5);
    lPanelLayout->addWidget(bXValue, 0, 1);
    QLabel *bYLabel = new QLabel("by value");
    lPanelLayout->addWidget(bYLabel, 0, 2, 1, 1);
    bYValue = new QDoubleSpinBox();
    bYValue->setRange(-100.0, 100.0);
    bYValue->setSingleStep(0.5);
    lPanelLayout->addWidget(bYValue, 0, 3, 1, 1);
    QLabel *bZLabel = new QLabel("bz value");
    lPanelLayout->addWidget(bZLabel, 0, 4, 1, 1);
    bZValue = new QDoubleSpinBox();
    bZValue->setRange(-100.0, 100.0);
    bZValue->setSingleStep(0.5);
    lPanelLayout->addWidget(bZValue, 0, 5, 1, 1);

    QLabel *dXLabel = new QLabel("dx value");
    lPanelLayout->addWidget(dXLabel, 1, 0);
    dXValue = new QDoubleSpinBox();
    dXValue->setRange(-100.0, 100.0);
    dXValue->setSingleStep(0.5);
    lPanelLayout->addWidget(dXValue, 1, 1);
    QLabel *dYLabel = new QLabel("dy value");
    lPanelLayout->addWidget(dYLabel, 1, 2, 1, 1);
    dYValue = new QDoubleSpinBox();
    dYValue->setRange(-100.0, 100.0);
    dYValue->setSingleStep(0.5);
    lPanelLayout->addWidget(dYValue, 1, 3, 1, 1);
    QLabel *dZLabel = new QLabel("dz value");
    lPanelLayout->addWidget(dZLabel, 1, 4, 1, 1);
    dZValue = new QDoubleSpinBox();
    dZValue->setRange(-100.0, 100.0);
    dZValue->setSingleStep(0.5);
    lPanelLayout->addWidget(dZValue, 1, 5, 1, 1);

    QPushButton *startRotationButton = new QPushButton("Start rotation");
    lPanelLayout->addWidget(startRotationButton, 2, 5);

    connect(startRotationButton, SIGNAL(clicked()), this, SLOT(setValues()));

    connect(this, SIGNAL(setValueFinished()), glView, SLOT(startLineRotation()));

    this->hide();
}

void LinePanel::setValues() {
    glView->setBVector(bXValue->value(), bYValue->value(), bZValue->value());
    glView->setDVector(dXValue->value(), dYValue->value(), dZValue->value());
    //qDebug() << angleValue->value();
    glView->setAngle(angleValue->value());
    emit setValueFinished();
}

void LinePanel::showLineRotationPanel() {
    if(this->isHidden())
        this->show();
    else
        this->hide();
}
