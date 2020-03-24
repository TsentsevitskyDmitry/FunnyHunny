#include "QSceneItem.h"
#include <cmath>

QSceneItem::QSceneItem(QString texturePath, int x, int y, int size, QObject *parent) : pim(texturePath)
{
    setPos(x, y);
    _size = size;
    _x = x;
    _y = y;
}

bool QSceneItem::isNear(QSceneItem *item)
{
    int dx = _x - item->getX();
    int dy = _y - item->getY();
    if(abs(dx) < _size / 2 && abs(dy) < _size / 2)
        return true;
    return false;
}

QRectF QSceneItem::boundingRect() const
{
    return QRectF (-_size/2,-_size/2,_size,_size);
}

void QSceneItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setPen(Qt::black);
    //painter->setBrush(pim.scaled(size, size,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    //painter->drawRect(0,0,size,size);

    painter->drawImage(QPoint(-_size/2,-_size/2), pim.scaled(_size, _size));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
