#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QMenu>

#include "imageProcess/excom.h"

class MainWindow;
class MainStage : public QWidget
{
    Q_OBJECT

public:
    MainStage(QWidget *parent = 0);

    MainWindow *p_mainwindow;

    QPixmap *img;

    Excom *excom;

    int pressed_xpos;
    int pressed_ypos;
    int current_xpos;
    int current_ypos;
    bool flag_left_down;

    bool loadImgbox();\
    void loadImgsbox();
    bool loadImage(QString);

    void connectKeyEvent(QKeyEvent *event);

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MAINVIEW_H
