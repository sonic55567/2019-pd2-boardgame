#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include "Chess.h"
#include "Button.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void displayMainMenu();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void pickUpChess(Chess *chess);

    // set chess board coordinate
    int getRightxPos(int pos);
    int getRightyPos(int pos);

    // set the turn of player
    QString getWhosTurn();
    void nextPlayer();

    // Mode

    void start();

    // GameOver
    void drawMessageBoard(int x, int y,int width,int height,QColor color,double opacity);
    void gameOver(QString winner);
    void displayGameOverWindow(QString message);

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;
    QString whosTurn;
    Chess *chessToPlace;
    Chess* chessPtr[32];
    int rEatenNum;
    int bEatenNum;

private:
    Ui::MainWindow *ui;
    QString mode;
    QGraphicsPixmapItem *Pointer;
    Button *remove;
    Button *change;
    Button *play;
    Button *editor;


public slots:
    void Game();
    void Editor();
    void restartGame();
    void restartMenu();
    void changeTurn();
    void editorToPlay();
    void editorRemove();
    void gameToEditor();

};

#endif // MAINWINDOW_H
