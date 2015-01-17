#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <math.h>
#include "linepanel.h"
#include "mainview.h"
#include "viewpanel.h"
#include <QDebug>
#define RADPERDEG 0.0174533

/*
void Arrow(GLdouble x1,GLdouble y1,GLdouble z1,GLdouble x2,GLdouble y2,GLdouble z2,GLdouble D)
{
  double x=x2-x1;
  double y=y2-y1;
  double z=z2-z1;
  double L=sqrt(x*x+y*y+z*z);

    GLUquadricObj *quadObj;

    glPushMatrix ();

      glTranslated(x1,y1,z1);

      if((x!=0.)||(y!=0.)) {
        glRotated(atan2(y,x)/RADPERDEG,0.,0.,1.);
        glRotated(atan2(sqrt(x*x+y*y),z)/RADPERDEG,0.,1.,0.);
      } else if (z<0){
        glRotated(180,1.,0.,0.);
      }

      glTranslatef(0,0,L-4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, 2*D, 0.0, 4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, 2*D, 32, 1);
      gluDeleteQuadric(quadObj);

      glTranslatef(0,0,-L+4*D);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluCylinder(quadObj, D, D, L-4*D, 32, 1);
      gluDeleteQuadric(quadObj);

      quadObj = gluNewQuadric ();
      gluQuadricDrawStyle (quadObj, GLU_FILL);
      gluQuadricNormals (quadObj, GLU_SMOOTH);
      gluDisk(quadObj, 0.0, D, 32, 1);
      gluDeleteQuadric(quadObj);

    glPopMatrix ();

}
void drawAxes(GLdouble length)
{
    glPushMatrix();
    glTranslatef(-length,0,0);
    Arrow(0,0,0, 2*length,0,0, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-length,0);
    Arrow(0,0,0, 0,2*length,0, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-length);
    Arrow(0,0,0, 0,0,2*length, 0.2);
    glPopMatrix();
}
*/


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

    win.show();

    return app.exec();
}
