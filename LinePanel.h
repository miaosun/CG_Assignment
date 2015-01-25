#ifndef LINEPANEL
#define LINEPANEL

#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>
#include <QDebug>
#include <QDoubleSpinBox>

#include "mainview.h"
#include "viewpanel.h"

class LinePanel : public QWidget {
    Q_OBJECT

private:
    MainView *glView;

    QGridLayout *lPanelLayout;
    QDoubleSpinBox *angleValue;
    QDoubleSpinBox *bXValue;
    QDoubleSpinBox *bYValue;
    QDoubleSpinBox *bZValue;
    QDoubleSpinBox *dXValue;
    QDoubleSpinBox *dYValue;
    QDoubleSpinBox *dZValue;
public:
    LinePanel(MainView *glView);
    void init();

public slots:
    void showLineRotationPanel();
    void setValues();

signals:
    void setValueFinished();
};

#endif // LINEPANEL

