#pragma once

#include <QImage>
#include <QQuickPaintedItem>

class MVideoPlayerItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit MVideoPlayerItem(QQuickItem *parent = 0);
    void paint(QPainter *painter);

public slots:
    Q_INVOKABLE void newFrameArrived(const QVector<QColor> *data);

private:
    QImage _image;
};
