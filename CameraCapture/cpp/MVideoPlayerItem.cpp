#include "MVideoPlayerItem.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>

MVideoPlayerItem::MVideoPlayerItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    this->setVisible(true);
    this->setFlag(QQuickItem::ItemHasContents);

    _image = QImage((int)this->width(), (int)this->height(), QImage::Format_ARGB32);
    _image.fill(QColor(255, 255, 255));
}

void MVideoPlayerItem::paint(QPainter *painter)
{
    painter->drawImage(QRect(0, 0, width(), height()), _image, QRect(0, 0, _image.width(), _image.height()));
}

void MVideoPlayerItem::newFrameArrived(const QVector<QColor> *data)
{
    QImage img((int)this->width(), (int)this->height(), QImage::Format_ARGB32);
    QPainter painter;
    painter.begin(&img);

    int cnt = 0;
    for (int y = 0; y < img.height(); y += 6)
    {
        for (int x = 0; x < img.width(); x += 1)
        {
            painter.setPen(data->at(cnt++));
            painter.drawRect(x, y, 1, 5);
        }
    }

    painter.end();

    _image = img;
    update();
}
