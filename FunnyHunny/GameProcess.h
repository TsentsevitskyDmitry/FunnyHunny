#ifndef GAMEPROCESS_H
#define GAMEPROCESS_H

#include <QObject>
#include <gamesettings.h>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>

class GameProcess: public QObject
{
Q_OBJECT

private:
    int _W, _H;
    QMediaPlayer *playerGood;
    QMediaPlayer *playerBad;

    static GameProcess* instance;
    bool aims[ANIM_COUNT] = {0};
    void mark(int index);
    void unmark(int index);
    bool all();

public:
    GameProcess() {
        playerGood = new QMediaPlayer;
        playerBad = new QMediaPlayer;
        playerGood->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators("./res/good.mp3")));
        playerGood->setVolume(100);
        playerBad->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators("./res/bad.mp3")));
        playerBad->setVolume(100);
    }
    ~GameProcess() {
        delete playerGood;
        delete playerBad;
    }
    static GameProcess *getInstance();
    void setWH(int W, int H);
    void check(int x, int y, int index, int group);


signals:
    void GameOver();
};

#endif // GAMEPROCESS_H
