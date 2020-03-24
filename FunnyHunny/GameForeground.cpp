#include "GameForeground.h"

GameForeground::GameForeground(QGraphicsScene* scene)
{
    _scene = scene;
}

void GameForeground::setup()
{
    for(int i = 0; i < ANIM_COUNT; ++i){
        int x = _scene->width() * foregroundItems[i].x;
        int y = _scene->height() * foregroundItems[i].y;
        AnimalItem* item = new AnimalItem(foregroundItems[i].texture, x, y, foregroundItems[i].index, foregroundItems[i].group);
        _scene->addItem(item);
    }
}
