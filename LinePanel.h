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

#include "mainview.h"
#include "viewpanel.h"

class LinePanel : public QGLWidget {
    Q_OBJECT

private:
    QWidget *lPanel;
    MainView *glView;
    QSignalMapper* signalMapper;

public:
    LinePanel(MainView *glView, const QGLFormat &format, QWidget *parent = 0);
    void init();
    QWidget* getLPanel();

public slots:
    void showLineRotationPanel();

signals:
    void clicked(QString);

};

#endif // LINEPANEL

