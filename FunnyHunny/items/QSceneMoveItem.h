#ifndef QSCENEMOVEITEM_H
#define QSCENEMOVEITEM_H

#include <QString>
#include "QSceneItem.h"

class QSceneMoveItem : public QSceneItem
{
protected:
    virtual void colisionCheck(int x, int y) = 0;

public:
    QSceneMoveItem(QString texturePath, int x, int y, int size);

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QSCENEMOVEITEM_H
