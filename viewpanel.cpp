
#include "viewpanel.h"

ViewPanel::ViewPanel(MainView *glView, const QGLFormat &format, QWidget *parent) : QGLWidget(format, parent) {
    this->glView = glView;
    vPanel = new QWidget(parent);
}

void ViewPanel::init() {
    QGridLayout *vPanelLayout = new QGridLayout();
    vPanel->setLayout(vPanelLayout);
    vPanelLayout->setSpacing(20);
    QLabel *eyeX = new QLabel("Eye position x");
    vPanelLayout->addWidget(eyeX, 0, 0);
    QLineEdit *e_edtX = new QLineEdit();
    vPanelLayout->addWidget(e_edtX, 0, 1);
    QLabel *eyeY = new QLabel("Eye position y");
    vPanelLayout->addWidget(eyeY, 0, 2);
    QLineEdit *e_edtY = new QLineEdit();
    vPanelLayout->addWidget(e_edtY, 0, 3);
    QLabel *eyeZ = new QLabel("Eye position z");
    vPanelLayout->addWidget(eyeZ, 0, 4, 1, 1);
    QLineEdit *e_edtZ = new QLineEdit();
    vPanelLayout->addWidget(e_edtZ, 0, 5, 1, 1);

    QLabel *orientX = new QLabel("Orientation x");
    vPanelLayout->addWidget(orientX, 1, 0, 1, 1);
    QLineEdit *o_edtX = new QLineEdit();
    vPanelLayout->addWidget(o_edtX, 1, 1, 1, 1);
    QLabel *orientY = new QLabel("Orientation y");
    vPanelLayout->addWidget(orientY, 1, 2, 1, 1);
    QLineEdit *o_edtY = new QLineEdit();
    vPanelLayout->addWidget(o_edtY, 1, 3, 1, 1);
    QLabel *orientZ = new QLabel("Orientation z");
    vPanelLayout->addWidget(orientZ, 1, 4, 1, 1);
    QLineEdit *o_edtZ = new QLineEdit();
    vPanelLayout->addWidget(o_edtZ, 1, 5, 1, 1);

    QPushButton *viewPositionButton = new QPushButton("View Position");
    vPanelLayout->addWidget(viewPositionButton);
    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);
    QObject::connect(viewPositionButton, SIGNAL(clicked()), glView, SLOT(viewPosition()));

    //mainLayout->addWidget(vPanel);

    vPanel->hide();

}

void ViewPanel::showViewPositionPanel() {

    if(vPanel->isHidden())
        vPanel->show();
    else
        vPanel->hide();
}

QWidget* ViewPanel::getVPanel() {
    return this->vPanel;
}
