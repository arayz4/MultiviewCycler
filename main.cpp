/******************************************************************************

Software    :    MultiViewCycler

File        :    main.cpp

Legal       :    Copyright 2016 Shunsuke izumi All rights reserved.

Author(s)   :    Shunsuke izumi
Date        :    2016/05/17

Description :    Nothing much

History     :    Onece apon a time in China

******************************************************************************/

#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QColor>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//日本語対応

    //Apperance//
    QPalette dark_palette(
        QBrush(QColor(230,230,230)), //window text
        QBrush(QColor(76,76,76)), //button
        QBrush(QColor(60,60,60)), //light
        QBrush(QColor(20,20,20)), //dark
        QBrush(QColor(40,40,40)), //mid
        QBrush(QColor(230,230,230)), //text
        QBrush(QColor(240,240,240)), //bright_text
        QBrush(QColor(100,100,100)), //base
        QBrush(QColor(50,50,50)) //window
        );
    //Disabled color
    dark_palette.setColor(QPalette::Disabled,QPalette::Text,QColor(20,20,20,0));
    dark_palette.setColor(QPalette::Disabled,QPalette::Base,QColor(20,20,20,0));
    dark_palette.setColor(QPalette::Disabled,QPalette::Button,QColor(20,20,20,0));
    w.setPalette(dark_palette);

    //Launch position
    w.setGeometry(100,100,400,300);
    w.show();

    return a.exec();
}
