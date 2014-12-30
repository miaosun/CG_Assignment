#ifndef VIEWPANEL
#define VIEWPANEL

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "mainview.h"
#include "LinePanel.h"

class ViewPanel : public QGLWidget {
    Q_OBJECT

private:
    QWidget *vPanel;
    MainView *glView;

public:
    ViewPanel(MainView *glView, const QGLFormat &format, QWidget *parent = 0);
    void init();
    QWidget* getVPanel();

public slots:
    void showViewPositionPanel();

};
#endif // VIEWPANEL

