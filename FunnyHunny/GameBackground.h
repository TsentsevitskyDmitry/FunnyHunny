#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H

#include <QGraphicsScene>
#include "items/HomeItem.h"
#include "GameSettings.h"

class GameBackground
{   
private:
    QGraphicsScene* _scene;

public:
    GameBackground(QGraphicsScene* scene);
    void setup();
};

#endif // GAMEBACKGROUND_H
