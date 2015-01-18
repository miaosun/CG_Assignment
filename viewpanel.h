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

class ViewPanel : public QWidget {
    Q_OBJECT

private:
    MainView *glView;

    QGridLayout *vPanelLayout;
    QDoubleSpinBox *eyeXValue;
    QDoubleSpinBox *eyeYValue;
    QDoubleSpinBox *eyeZValue;
    QDoubleSpinBox *directXValue;
    QDoubleSpinBox *directYValue;
    QDoubleSpinBox *directZValue;

public:
    ViewPanel(MainView *glView);
    void init();

public slots:
    void showViewPositionPanel();
    void setValues();

signals:
    void setValuesFinished();
};
#endif // VIEWPANEL

