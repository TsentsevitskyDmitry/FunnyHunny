#ifndef HOMEITEM_H
#define HOMEITEM_H

#include "QSceneItem.h"
#include "GameSettings.h"

class HomeItem : public QSceneItem
{
public:
    HomeItem(QString texturePath, int x, int y);
};

#endif // HOMEITEM_H
