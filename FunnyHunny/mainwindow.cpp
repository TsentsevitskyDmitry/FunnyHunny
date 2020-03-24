#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameProcess.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(GameProcess::getInstance(), SIGNAL(GameOver()), this, SLOT(GameOver()));

    setupScene();
    setupGameBackground();
    // menu here
    setupGameForeground();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gback;
    delete gfront;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Escape)
    {
         QCoreApplication::quit();
    }
    else
        QWidget::keyPressEvent(event);
}

void MainWindow::setupScene()
{
    // Косметическая подготовка приложения
    this->showFullScreen();
    this->resize(1920,1080);          // Устанавливаем размеры окна приложения
    this->setFixedSize(1920,1080);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(1920,1080);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    scene->setSceneRect(0,0,1895,1055); // Устанавливаем размер сцены
    GameProcess::getInstance()->setWH(scene->width(), scene->height());

    gback = new GameBackground(scene);
    gfront = new GameForeground(scene);
}

void MainWindow::setupGameBackground()
{
    gback->setup();
}

void MainWindow::setupGameForeground()
{
    gfront->setup();
}

void MainWindow::GameOver()
{
    scene->clear();
    QPixmap pim("./res/win.bmp");
    scene->setBackgroundBrush(pim.scaled(scene->width(), scene->height(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
