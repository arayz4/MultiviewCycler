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
