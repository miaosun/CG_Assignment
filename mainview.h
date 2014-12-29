#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "/usr/include/GL/glew.h"

#include <QGLWidget>
#include <QTimer>

#include "scene.h"

class MainView : public QGLWidget
{
    Q_OBJECT

private:
    QTimer *timer;
    Scene *scene;
    float t;

public:
    MainView( const QGLFormat & format, QWidget *parent = 0 );

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void timerUpdate();
    void viewPosition();
    void startLineRotation(float t);
    void defaultView();
};

#endif // MAINVIEW_H
