
#include "viewpanel.h"

ViewPanel::ViewPanel(MainView *glView) : QWidget() {
    this->glView = glView;

    init();
}

void ViewPanel::init() {
    vPanelLayout = new QGridLayout();
    this->setLayout(vPanelLayout);
    vPanelLayout->setSpacing(20);
    QLabel *eyeXLabel = new QLabel("Eye position x");
    vPanelLayout->addWidget(eyeXLabel, 0, 0);
    eyeXValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(eyeXValue, 0, 1);
    QLabel *eyeYLabel = new QLabel("Eye position y");
    vPanelLayout->addWidget(eyeYLabel, 0, 2);
    eyeYValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(eyeYValue, 0, 3);
    QLabel *eyeZLabel = new QLabel("Eye position z");
    vPanelLayout->addWidget(eyeZLabel, 0, 4, 1, 1);
    eyeZValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(eyeZValue, 0, 5, 1, 1);

    QLabel *directXLabel = new QLabel("Orientation x");
    vPanelLayout->addWidget(directXLabel, 1, 0, 1, 1);
    directXValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(directXValue, 1, 1, 1, 1);
    QLabel *directYLabel = new QLabel("Orientation y");
    vPanelLayout->addWidget(directYLabel, 1, 2, 1, 1);
    directYValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(directYValue, 1, 3, 1, 1);
    QLabel *directZLabel = new QLabel("Orientation z");
    vPanelLayout->addWidget(directZLabel, 1, 4, 1, 1);
    directZValue = new QDoubleSpinBox();
    vPanelLayout->addWidget(directZValue, 1, 5, 1, 1);

    QPushButton *changeViewButton = new QPushButton("Change View Position");
    vPanelLayout->addWidget(changeViewButton);
    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);

    QObject::connect(changeViewButton, SIGNAL(clicked()), this, SLOT(setValues()));

    QObject::connect(this, SIGNAL(setValuesFinished()), glView, SLOT(viewPosition()));

    this->hide();
}

void ViewPanel::showViewPositionPanel() {

    if(this->isHidden())
        this->show();
    else
        this->hide();
}

/*
 * get the values of input and then emit setValuesFinished signal.
 */
void ViewPanel::setValues()
{
    glView->setEye(eyeXValue->value(), eyeYValue->value(), eyeZValue->value());
    glView->setDirection(directXValue->value(), directYValue->value(), directZValue->value());

    emit setValuesFinished();
}
