#include "mainview.h"
#include "scenebasic.h"
#include "glutils.h"
#include <iostream>
#include <cstdio>
#include <QDebug>
using std::cout;
using std::endl;

#include <QMouseEvent>
#include <QWheelEvent>

MainView::MainView(const QGLFormat & format, QWidget *parent) : QGLWidget(format, parent)
{
    // This tells the widget to accept keyboard focus when the widget is clicked.
    this->setFocusPolicy(Qt::ClickFocus);

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(timerUpdate()) );
    timer->start(50);
    /*
    alpha = 0.0;
    beta = 0.0;
    distance = 2.5;
*/
    this->setMinimumSize(800,600);
}

void MainView::initializeGL() {

    //////////////// PLUG IN SCENE HERE /////////////////
    scene = new SceneBasic();
    ////////////////////////////////////////////////////
    GLenum err = glewInit();
    if( GLEW_OK != err )
    {
        cout <<"Error initializing GLEW: " << glewGetErrorString(err) << endl;
    }
   // GLUtils::checkForOpenGLError(__FILE__,__LINE__);
     GLUtils::checkForOpenGLError();

    QGLFormat format = this->format();
    printf("QGLFormat reports profile: ");
    if( format.profile() == QGLFormat::CompatibilityProfile )
        printf("compatability.\n");
    else if( format.profile() == QGLFormat::CoreProfile )
        printf("core.\n");
    else
        printf("none.\n");

    GLUtils::dumpGLInfo();

    glClearColor(0.0f,0.0f,0.0f,1.0f);

    scene->initScene();
}

void MainView::paintGL() {
    GLUtils::checkForOpenGLError();
    scene->render();
}

void MainView::resizeGL(int w, int h ) {
    scene->resize(w,h);
}

void MainView::startLineRotation() { //TODO: modify function
    scene->setLineVector(bVector, dVector);
}

void MainView::viewPosition() {
    scene->setEye(eyeVs);
    scene->setDirection(directionVs);
}

void MainView::defaultView() {
    setEye(0, 0, 2);
    setDirection(0, 0, -1);
    scene->setEye(eyeVs);
    scene->setDirection(directionVs);
    this->setAngle(0.0f);
    scene->setAngle(0.0f);

}

void MainView::timerUpdate() {
    scene->update(angle_f);
    updateGL();
}

void MainView::setEye(double x, double y, double z)
{
    this->eyeVs[0] = x;
    this->eyeVs[1] = y;
    this->eyeVs[2] = z;
}

void MainView::setDirection(double x, double y, double z)
{
    this->directionVs[0] = x;
    this->directionVs[1] = y;
    this->directionVs[2] = z;
}

void MainView::setBVector(double x, double y, double z)
{
    this->bVector[0] = x;
    this->bVector[1] = y;
    this->bVector[2] = z;
}

void MainView::setDVector(double x, double y, double z)
{
    this->dVector[0] = x;
    this->dVector[1] = y;
    this->dVector[2] = z;
}

void MainView::setAngle(float angle)
{
    this->angle_f = angle;
}

