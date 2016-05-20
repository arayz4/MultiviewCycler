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
    int picsize = 9;
    if(slist.size() != picsize)
        return QImage();

    QVector<QImage> array_img(picsize);
    for ( int i = 0; i < picsize; i++){
        array_img[i].load(slist[i]);
    }

    //Check size
    int fwid = array_img.first().width();
    int fhig = array_img.first().height();

    //Width check
    for ( int i = 1; i < picsize; i++){
        if(fwid != array_img[i].width())
        {
            qDebug() << "Please, make sure every image is same size";
            return QImage();
        }
    }

    //Height check
    for ( int i = 1; i < picsize; i++){
        if(fhig != array_img[i].height())
        {
            qDebug() << "Please, make sure every image is same size";
            return QImage();
        }
    }

    QImage blankImage(fwid,fhig,array_img.first().format());

    blankImage.fill(QColor(100,255,100,255));

    int shiftnum;

    for (int y = 0; y < fhig; y++){
        shiftnum = 0;

        for (int x = 0; x < fwid; x++){
            blankImage.setPixel(x,y,array_img.at(shiftnum).pixel(x,y));

            if(shiftnum < picsize - 1){
                shiftnum++;
            }else{
                shiftnum = 0;
            }
        }
    }



    return blankImage;
}
