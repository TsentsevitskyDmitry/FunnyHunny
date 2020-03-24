#include "AnimalItem.h"

AnimalItem::AnimalItem(QString texturePath, int x, int y, int index, int group) :
    QSceneMoveItem (texturePath, x, y, ANIMAL_SIZE)
{
    _index = index;
    _group = group;
}

void AnimalItem::colisionCheck(int x, int y)
{
    GameProcess::getInstance()->check(x, y, _index, _group);
}
