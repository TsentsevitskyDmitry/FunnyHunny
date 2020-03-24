#ifndef GAMEFOREGROUND_H
#define GAMEFOREGROUND_H

#include <QGraphicsScene>
#include "items/AnimalItem.h"
#include "GameSettings.h"

class GameForeground
{
private:
    QGraphicsScene* _scene;

public:
    GameForeground(QGraphicsScene* scene);
    void setup();
};

#endif // GAMEFOREGROUND_H
