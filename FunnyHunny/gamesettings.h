#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <QString>

typedef struct
{
    QString texture;
    float x;
    float y;
    int index;
    int group;
} itemSettings;

const int ANIMAL_SIZE = 210;
const int HOME_SIZE = 250;

const int ANIM_COUNT = 9;
const int HOME_COUNT = 5;

const itemSettings foregroundItems[ANIM_COUNT] = {{"./res/dog", 0.49, 0.41, 0, 0}, {"./res/cat.png", 0.51, 0.50, 1, 1}, {"./res/sheep", 0.5, 0.61, 2, 4}, {"./res/pig", 0.41, 0.38, 3, 4}, {"./res/chicken", 0.38, 0.48, 4, 3}, {"./res/petyh", 0.38, 0.61, 5, 3}, {"./res/house", 0.59, 0.41, 6, 2}, {"./res/korova", 0.61, 0.49, 7, 4}, {"./res/koza", 0.61, 0.58, 8, 4}};
const itemSettings backgroundItems[HOME_COUNT] = {{"./res/h3", 0.72, 0.22, 0, 0}, {"./res/h3", 0.5, 0.22, 1, 1}, {"./res/h3", 0.25, 0.35, 2, 2}, {"./res/h3", 0.84, 0.46, 3, 3}, {"./res/h3", 0.25, 0.75, 4, 4}};
                                                   //     budka                      //  home                       //  loshad                    //    kyrica                  //      sarai
const QString backgroundPath = "./res/back.bmp";

#endif // GAMESETTINGS_H
