#include "mainview.h"
#include "mainwindow.h"

MainStage::MainStage(QWidget *parent)
    : QWidget(parent)
{
    img = new QImage;
    excom = new Excom;
}

void MainStage::paintEvent(QPaintEvent *)//描画イベント
{
    QPainter paint;
    paint.begin(this);
    if(!img->isNull()){
        paint.drawImage(0,0,*img);
    }
    paint.end();
}

bool MainStage::loadImgbox()
{
    QFileDialog::Options options;
        QString strSelectedFilter;
        QString strFName = QFileDialog::getOpenFileName(
                this,
                tr( "Open single Image file" ),
                ".",
                tr( "*.jpg" ),
                &strSelectedFilter, options );

    if(strFName.isEmpty())
        return false;
    else
        loadImage(strFName);
        return true;
}

bool MainStage::loadImage(QString filepath)
{
    bool success;
    success = img->load(filepath);
    return success;
}

void MainStage::loadImgsbox()
{
    QFileDialog::Options options;
        QString strSelectedFilter;
        QStringList strFNames = QFileDialog::getOpenFileNames(
                this,
                tr( "Select 9 Image files" ),
                ".",
                tr( "*.jpg" ),
                &strSelectedFilter, options );

    if(strFNames.isEmpty() || strFNames.size() != 9){
        return;
    }else{
        *img = excom->combine_01(strFNames);
    }
}

//-----------SHORT CUT KEY ASSIGN--------------//
void MainStage::connectKeyEvent(QKeyEvent *event)
{
    this->keyPressEvent(event);
}

void MainStage::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Enter:
        case Qt:: Key_Return:
        {
            p_mainwindow->slot_fullscreen();
            break;
        }

    case Qt::Key_O:
        {
            this->loadImgbox();
            break;
        }
    }
}

//--------------MOUSE KEY ASSIGN---------------//
void MainStage::mousePressEvent(QMouseEvent *event){
    this->setFocus();

    pressed_xpos = event->x();
    pressed_ypos = event->y();

    if(event->button() == Qt::LeftButton){
        if(!p_mainwindow->isFullScreen()){
            flag_left_down = true;
        }
    }
}

void MainStage::mouseReleaseEvent(QMouseEvent *event){
    pressed_xpos = 0;pressed_ypos = 0;current_xpos = 0;current_ypos = 0;
    if(event->button() == Qt::LeftButton){
            flag_left_down = false;
    }
}

void MainStage::mouseMoveEvent(QMouseEvent *event){
    current_xpos = event->x();
    current_ypos = event->y();

    if(flag_left_down){
        QPoint xy_pressed(pressed_xpos, pressed_ypos);
        QPoint diff = event->pos() - xy_pressed;
        p_mainwindow->move(p_mainwindow->pos() + diff);
    }
}

void MainStage::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        p_mainwindow->slot_fullscreen();
    }
}

void MainStage::contextMenuEvent(QContextMenuEvent *event){
    QMenu *menuRight  = new QMenu(this);\
    menuRight->addAction(p_mainwindow->act_openimage);
    menuRight->addAction(p_mainwindow->act_open9images);
    menuRight->addAction(p_mainwindow->act_fullscreen);
    menuRight->addAction(p_mainwindow->act_quit);

    QPoint menuLocation = event->globalPos();
    menuRight->exec(QPoint(menuLocation.x() ,menuLocation.y()));
}
