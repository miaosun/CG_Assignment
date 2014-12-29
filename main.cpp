#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

#include "LinePanel.h"
#include "mainview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // The main window
    QWidget win;

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

    QPushButton *lRotationButton = new QPushButton("Line Rotation");
    cPanelLayout->addWidget(lRotationButton);
    QObject::connect( lRotationButton, SIGNAL(clicked()), lPanel, SLOT(showLineRotationPanel()) );

    QPushButton *vPositionButton = new QPushButton("View Position");
    cPanelLayout->addWidget(vPositionButton);
    QObject::connect(vPositionButton, SIGNAL(clicked()), glView, SLOT(viewPosition()) );

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

    mainLayout->addWidget(lPanel->getLPanel());
    /*
    //
    // line rotation panel
    //
    QWidget *lPanel = new QWidget(&win);
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
    //lPanelLayout->setAlignment(startRotationButton, Qt::AlignHCenter);
    QObject::connect(startRotationButton, SIGNAL(clicked()), glView, SLOT(startRotation()));

    mainLayout->addWidget(lPanel);

    lPanel->hide();
    //
    // end line rotation panel
    //
*/

    //
    // view position panel
    //
    QWidget *vPanel = new QWidget(&win);
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

    mainLayout->addWidget(vPanel);

    vPanel->hide();
    //
    // end view postion panel
    //


    win.setLayout(mainLayout);
    win.setWindowTitle("CG Assignment");
    win.show();

    return app.exec();
}
