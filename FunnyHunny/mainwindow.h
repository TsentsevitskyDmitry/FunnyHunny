#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "GameBackground.h"
#include "GameForeground.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    GameBackground *gback;
    GameForeground *gfront;

    void setupScene();
    void setupGameBackground();
    void setupGameForeground();
    void keyPressEvent(QKeyEvent* event);

public slots:
    void GameOver();

};

#endif // MAINWINDOW_H
