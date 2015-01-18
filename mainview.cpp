#include "mainview.h"
#include "scenebasic.h"
#include "glutils.h"
#include <iostream>
#include <cstdio>
#include <QDebug>
using std::cout;
using std::endl;


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
    //QImage img = this->grabFrameBuffer(true);
    //img.save("screen.png", "PNG");

    qDebug() << "Inside startLineRotation(Qstring string)";
    scene->setLine(line);
}

void MainView::viewPosition() { //TODO: modify function
/*    if( timer->isActive() )
        timer->stop();
    else
        timer->start();
*/
    scene->setEye(eyeVs);
    scene->setDirection(directionVs);

}

void MainView::defaultView() { //TODO:
    setEye(0, 0, 2);
    setDirection(0, 0, -1);
    scene->setEye(eyeVs);
    scene->setDirection(directionVs);

}

void MainView::timerUpdate() {
    scene->update(0.0f);
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

void MainView::setLine(double x, double y, double z)
{
    this->line[0] = x;
    this->line[1] = y;
    this->line[2] = z;
}
