#include "GameProcess.h"

GameProcess* GameProcess::instance = nullptr;

GameProcess *GameProcess::getInstance()
{
    if(instance == nullptr)
        instance = new GameProcess;

    return instance;
}


void GameProcess::setWH(int W, int H)
{
    _W = W;
    _H = H;
}

void GameProcess::check(int x, int y, int index, int group)
{
    for(int i = 0; i < HOME_COUNT; ++i){
        if(backgroundItems[i].group != group)
            continue;

        int dx = backgroundItems[i].x * _W - x;
        int dy = backgroundItems[i].y * _H - y;

        if(abs(dx) < HOME_SIZE && abs(dy) < HOME_SIZE)
            mark(index);
       else
            unmark(index);
    }
}

void GameProcess::mark(int index)
{
    playerGood->play();
    aims[index] = true;
    if(all())
        emit GameOver();
}

void GameProcess::unmark(int index)
{
    playerBad->play();
    aims[index] = false;
}

bool GameProcess::all()
{
    for(int i = 0; i < ANIM_COUNT; ++i){
        if(aims[i] == false)
            return false;
    }
    return true;
}
