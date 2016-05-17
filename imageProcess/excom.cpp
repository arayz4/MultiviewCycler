#include "excom.h"
#include "../mainview.h"

Excom::Excom(QWidget *parent)
    : QWidget(parent)
{

}

QImage Excom::testMirror(QStringList slist)
{
    QString firstImg;
    firstImg = slist.first();
    QImage qImgBuf,qImgRes;
    qImgBuf.load(firstImg);
    qImgRes = qImgBuf.mirrored(true,true);

    return qImgRes;
}

//FIX input 9 / display regular
QImage Excom::combine_01(QStringList slist)
{
    if(slist.size() != 9)
        return QImage();

    QVector<QImage> array_img(9);
    for ( int i = 0; i < 9; i++){
        array_img[i].load(slist[i]);
    }

    //Check size
    int fwid = array_img.first().width();
    int fhig = array_img.first().height();

    //Width check
    for ( int i = 1; i < 9; i++){
        if(fwid != array_img[i].width())
        {
            qDebug() << "Please, make sure every image same size";
            return QImage();
        }
    }

    //Height check
    for ( int i = 1; i < 9; i++){
        if(fhig != array_img[i].height())
        {
            qDebug() << "Please, make sure every image same size";
            return QImage();
        }
    }

    QImage blankImage(fwid,fhig,array_img.first().format());

    qDebug() << "go fuck ur self bitch";

    blankImage.fill(QColor(100,255,100,255));



    return blankImage;
}
