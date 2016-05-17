#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include "mainview.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MainStage *mainview;

    void makeMenu();
    QMenuBar *menubar;
    QAction *act_openimage;
    QAction *act_fullscreen;
    QAction *act_quit;

public slots:
    void slot_openimage();
    void slot_fullscreen();
    void slot_quitApp();

protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINWINDOW_H
