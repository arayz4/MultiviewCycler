#ifndef EXCOM_H
#define EXCOM_H

#include <QtGui>
#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QMenu>

class MainStage;
class Excom : public QWidget
{
    Q_OBJECT

public:
    Excom(QWidget *parent = 0);

    QImage testMirror(QStringList);

    MainStage *p_mainwindow;

};

#endif // EXCOM_H
