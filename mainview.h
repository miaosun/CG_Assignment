#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "/usr/include/GL/glew.h"

#include <QGLWidget>
#include <QTimer>

#include "scenebasic.h"

class MainView : public QGLWidget
{
    Q_OBJECT

private:
    QTimer *timer;
    SceneBasic *scene;
    double eyeVs[3];
    double directionVs[3];
    double line[3];
public:
    MainView( const QGLFormat & format, QWidget *parent = 0 );
    void setEye(double x, double y, double z);
    void setDirection(double x, double y, double z);
    void setLine(double x, double y, double z);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void timerUpdate();
    void viewPosition();
    void startLineRotation();
    void defaultView();
};

#endif // MAINVIEW_H
