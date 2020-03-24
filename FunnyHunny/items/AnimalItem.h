#ifndef ANIMALITEM_H
#define ANIMALITEM_H

#include "QSceneMoveItem.h"
#include "GameSettings.h"
#include "GameProcess.h"

class AnimalItem: public QSceneMoveItem
{
public:
    AnimalItem(QString texturePath, int x, int y, int index, int group);

private:
    int _index;
    int _group;
    void colisionCheck(int x, int y);
};

#endif // ANIMALITEM_H
