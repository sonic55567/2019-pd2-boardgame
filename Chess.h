#ifndef CHESS_H
#define CHESS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QString>



class Chess : public QObject,public QGraphicsPixmapItem
{

public:
    Chess();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // getters
    //bool getIsPlaced();
    QString getOwner();
    QString getType();
    int getxPos();
    int getyPos();

    //setters
    //void setIsPlaced(bool b);
    void setOwner(QString player);
    void setType(QString chessType);

    // set position
    void setxPos(int x);
    void setyPos(int y);

    // check the step
    bool checkStep(int x,int y);
    bool checkHasChess(int x,int y);
    bool checkPaoEatStep(int x,int y);
    bool checkGeneralFaceToFace(int x,int y);

private:
    QString owner;
    QString type;
    int xPos,yPos;
    int redEatenxPos[16] = {710,780,850,920,990,1060,710,780,850,920,990,1060,710,780,850,920};
    int redEatenyPos[16] = {530,530,530,530,530,530,600,600,600,600,600,600,670,670,670,670};
    int blackEatenxPos[16] = {710,780,850,920,990,1060,710,780,850,920,990,1060,710,780,850,920};
    int blackEatenyPos[16] = {170,170,170,170,170,170,100,100,100,100,100,100,30,30,30,30};


};

#endif // CHESS_H
