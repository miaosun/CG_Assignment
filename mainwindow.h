#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
