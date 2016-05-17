#ifndef EXCOM_H
#define EXCOM_H

#include <QtGui>
#include <QWidget>
#include <QImage>
#include <QDebug>
#include <QMenu>
#include <QVector>

class MainStage;
class Excom : public QWidget
{
    Q_OBJECT

public:
    Excom(QWidget *parent = 0);

    QImage testMirror(QStringList);
    QImage combine_01(QStringList);

    MainStage *p_mainwindow;

};

#endif // EXCOM_H
