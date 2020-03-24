#ifndef QSCENEITEM_H
#define QSCENEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class  QSceneItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

protected:
    int _size;
    int _x, _y;

    bool isNear(QSceneItem* item);

public:
    explicit QSceneItem(QString texturePath, int x, int y, int size, QObject *parent = 0);

    int getX() { return _x; }
    int getY() { return _y; }

private:
    QImage pim;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // QSCENEITEM_H
