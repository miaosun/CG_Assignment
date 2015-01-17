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
#include "linepanel.h"

class ViewPanel : public QGLWidget {
    Q_OBJECT

private:
    QWidget *vPanel;
    MainView *glView;

    QGridLayout *vPanelLayout;
    QDoubleSpinBox *eyeXValue;
    QDoubleSpinBox *eyeYValue;
    QDoubleSpinBox *eyeZValue;
    QDoubleSpinBox *directXValue;
    QDoubleSpinBox *directYValue;
    QDoubleSpinBox *directZValue;

public:
    ViewPanel(MainView *glView, const QGLFormat &format, QWidget *parent = 0);
    void init();
    QWidget* getVPanel();

public slots:
    void showViewPositionPanel();
    void setValues();

};
#endif // VIEWPANEL

