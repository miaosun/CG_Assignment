#include "linePanel.h"

LinePanel::LinePanel(MainView *glView, const QGLFormat &format, QWidget *parent) : QGLWidget(format, parent) {
    this->glView = glView;
    lPanel = new QWidget(parent);

}

void LinePanel::init() {
    QGridLayout *lPanelLayout = new QGridLayout();
    lPanel->setLayout(lPanelLayout);
    lPanelLayout->setSpacing(20);
    QLabel *angle = new QLabel("Angle");
    lPanelLayout->addWidget(angle, 0, 0);
    QLineEdit *edt1 = new QLineEdit();
    lPanelLayout->addWidget(edt1, 0, 1);
    QLabel *xValue = new QLabel("x value");
    lPanelLayout->addWidget(xValue, 0, 2);
    QLineEdit *edt2 = new QLineEdit();
    lPanelLayout->addWidget(edt2, 0, 3);
    QLabel *yValue = new QLabel("y value");
    lPanelLayout->addWidget(yValue, 1, 0, 1, 1);
    QLineEdit *edt3 = new QLineEdit();
    lPanelLayout->addWidget(edt3, 1, 1, 1, 1);
    QLabel *zValue = new QLabel("z value");
    lPanelLayout->addWidget(zValue, 1, 2, 1, 1);
    QLineEdit *edt4 = new QLineEdit();
    lPanelLayout->addWidget(edt4, 1, 3, 1, 1);

    QPushButton *startRotationButton = new QPushButton("Start rotation");
    lPanelLayout->addWidget(startRotationButton);

    //float t = edt1->text().toFloat();

    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);
    //QObject::connect(startRotationButton, SIGNAL(clicked()), glView, SLOT(startLineRotation()));

    signalMapper = new QSignalMapper(startRotationButton);

    //connect(startRotationButton, SIGNAL(clicked()), this, SLOT(showLineRotationPanel()));


    connect(startRotationButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QString string = edt1->text()+" "+edt2->text()+" "+edt3->text()+" "+edt4->text();
    qDebug() << string;
    signalMapper->setMapping(startRotationButton, string);
    connect(signalMapper, SIGNAL(mapped(QString)), glView, SLOT(startLineRotation(QString)));
    //connect(signalMapper, SIGNAL(mapped(QString)),startRotationButton, SIGNAL(clicked()));
    //connect(startRotationButton, SIGNAL(clicked()),glView, SLOT(startLineRotation(QString)));
    //connect(signalMapper, SIGNAL(mapped(QString)),glView, SLOT(startLineRotation(QString)));

    //mainLayout->addWidget(lPanel);
    lPanel->hide();
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
