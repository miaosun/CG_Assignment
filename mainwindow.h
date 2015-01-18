#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linepanel.h"
#include "viewpanel.h"
#include "mainview.h"

/*
namespace Ui {
class MainWindow;
}*/

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    MainView *glView;
    LinePanel *lPanel;
    ViewPanel *vPanel;

public:
    explicit MainWindow(QWidget *parent = 0);
    void init();
    ~MainWindow();

public slots:
    void showLineRotationPanel();
    void showViewPositionPanel();

private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
