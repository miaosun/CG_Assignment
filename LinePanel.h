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

class LinePanel : public QGLWidget {
    Q_OBJECT

private:
    QWidget *lPanel;
    MainView *glView;
    QSignalMapper* signalMapper;

    QGridLayout *lPanelLayout;
    QDoubleSpinBox *angleValue;
    QDoubleSpinBox *xValue;
    QDoubleSpinBox *yValue;
    QDoubleSpinBox *zValue;
    QString string;
public:
    LinePanel(MainView *glView, const QGLFormat &format, QWidget *parent = 0);
    void init();
    QWidget* getLPanel();
    QString getString();

public slots:
    void showLineRotationPanel();
    void setValues();

signals:
    void setValueFinished();
};

#endif // LINEPANEL

