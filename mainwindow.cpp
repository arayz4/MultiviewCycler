#include "mainwindow.h"
#include <QMenuBar>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainview = new MainStage;
    this->setCentralWidget(mainview);
    mainview->p_mainwindow = this;

    makeMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    mainview->connectKeyEvent(event);
}

//メニューバー
void MainWindow::makeMenu()
{
    QString title1 = QString::fromLocal8Bit("File");
    QString title2 = QString::fromLocal8Bit("Help");
    //親メニュー
    QMenu* menu1 = new QMenu(title1, this);
    QMenu* menu2 = new QMenu(title2, this);
    //子メニューの作成
    //QMenu* m1_open = new QMenu(QString::fromLocal8Bit("Open"));
    //親メニューに子メニューの追加
    //menu1->addMenu(m1_open);
    //親メニューに項目の追加

    act_openimage = new QAction(tr("&Open Image"), this);
    QObject::connect(act_openimage,SIGNAL(triggered()),this, SLOT(slot_openimage()));

    act_open9images = new QAction(tr("&Open 9 Images"), this);
    QObject::connect(act_open9images,SIGNAL(triggered()),this, SLOT(slot_open9images()));

    act_fullscreen = new QAction(tr("&FullScreen"), this);
    act_fullscreen->setCheckable(true);
    QObject::connect(act_fullscreen,SIGNAL(triggered()), this, SLOT(slot_fullscreen()));

    act_quit = new QAction(tr("&Quit"), this);
    QObject::connect(act_quit,SIGNAL(triggered()),this, SLOT(slot_quitApp()));

    menu1->addAction(act_openimage);
    menu1->addSeparator();
    menu1->addAction(act_open9images);
    menu1->addSeparator();
    menu1->addAction(act_fullscreen);
    menu1->addSeparator();
    menu1->addAction(act_quit);

    menu2->addAction(QString::fromLocal8Bit("Help"));

    menubar = this->menuBar();
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
}

void MainWindow::slot_openimage()
{
    mainview->loadImgbox();
}

void MainWindow::slot_open9images()
{
    mainview->loadImgsbox();
}

void MainWindow::slot_fullscreen()
{
    if(this->isFullScreen()){
        if(menubar->isHidden()){
            menubar->show();
        }
        this->showNormal();
    }else{
        if(menubar->isVisible()){
            menubar->hide();
        }
        this->showFullScreen();
    }
}

void MainWindow::slot_quitApp()
{
    QApplication::quit();
}
