#include "GameBackground.h"

GameBackground::GameBackground(QGraphicsScene* scene)
{
    _scene = scene;
}

void GameBackground::setup()
{
    QPixmap pim("./res/back.bmp");
    _scene->setBackgroundBrush(pim.scaled(_scene->width(), _scene->height(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    for(int i = 0; i < HOME_COUNT; ++i){
        int x = _scene->width() * backgroundItems[i].x;
        int y = _scene->height() * backgroundItems[i].y;
        HomeItem* item = new HomeItem(backgroundItems[i].texture, x, y);
        _scene->addItem(item);
    }
}
