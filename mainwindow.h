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

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    MainView *mainview;
    LinePanel *lPanel;
    ViewPanel *vPanel;

public:
    explicit MainWindow(QWidget *parent = 0);
    void init();
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
