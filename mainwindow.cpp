#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Button.h"
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    this->scene = new QGraphicsScene(0,0,ui->board->width()-2,ui->board->height()-2);
    ui->board->setScene(scene);
    ui->board->setBackgroundBrush(QBrush("#F3BF6C",Qt::SolidPattern));
    ui->centralWidget->setMouseTracking(true);
    //setMouseTracking(true);


}

void MainWindow::start()
{

    //if()
    // who's turn
    whosTurn = "Red";
    qDebug()<<getWhosTurn();

    // pick up chess
    chessToPlace = nullptr;

    // initialize
    for(int i=0;i<32;++i){
        chessPtr[i] = nullptr;
    }

    QPixmap pixmap;
    QPixmap b1,b2,b3,b4,b5,b6,b7;
    QPixmap r1,r2,r3,r4,r5,r6,r7;

    pixmap.load(":/new/prefix1/board");                 // Load chessboard
    pixmap = pixmap.scaled(700,764,Qt::KeepAspectRatio);
    scene->addPixmap(pixmap);

    b1.load(":/new/prefix1/B1");  //load chess
    b2.load(":/new/prefix1/B2");
    b3.load(":/new/prefix1/B3");
    b4.load(":/new/prefix1/B4");
    b5.load(":/new/prefix1/B5");
    b6.load(":/new/prefix1/B6");
    b7.load(":/new/prefix1/B7");
    r1.load(":/new/prefix1/R1");
    r2.load(":/new/prefix1/R2");
    r3.load(":/new/prefix1/R3");
    r4.load(":/new/prefix1/R4");
    r5.load(":/new/prefix1/R5");
    r6.load(":/new/prefix1/R6");
    r7.load(":/new/prefix1/R7");
    b1 = b1.scaled(70,70,Qt::KeepAspectRatio);
    b2 = b2.scaled(70,70,Qt::KeepAspectRatio);
    b3 = b3.scaled(70,70,Qt::KeepAspectRatio);
    b4 = b4.scaled(70,70,Qt::KeepAspectRatio);
    b5 = b5.scaled(70,70,Qt::KeepAspectRatio);
    b6 = b6.scaled(70,70,Qt::KeepAspectRatio);
    b7 = b7.scaled(70,70,Qt::KeepAspectRatio);
    r1 = r1.scaled(70,70,Qt::KeepAspectRatio);
    r2 = r2.scaled(70,70,Qt::KeepAspectRatio);
    r3 = r3.scaled(70,70,Qt::KeepAspectRatio);
    r4 = r4.scaled(70,70,Qt::KeepAspectRatio);
    r5 = r5.scaled(70,70,Qt::KeepAspectRatio);
    r6 = r6.scaled(70,70,Qt::KeepAspectRatio);
    r7 = r7.scaled(70,70,Qt::KeepAspectRatio);

    int count = 0;
    for(int j=0 ; j<10 ; ++j){
        for(int i=0 ; i<9 ; ++i){
            Chess *chess = new Chess();
            chess->setPos(15+74*i,15+74*j);

            // initialize the chess
            // BLACK CHESS
            if(j==0){
                if(i==0 || i==8){
                    scene->addItem(chess);
                    chess->setPixmap(b4);
                    chess->setOwner("Black");
                    chess->setType("4");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==1 || i==7){
                    scene->addItem(chess);
                    chess->setPixmap(b5);
                    chess->setOwner("Black");
                    chess->setType("5");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==2 || i==6){
                    scene->addItem(chess);
                    chess->setPixmap(b3);
                    chess->setOwner("Black");
                    chess->setType("3");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==3 || i==5){
                    scene->addItem(chess);
                    chess->setPixmap(b2);
                    chess->setOwner("Black");
                    chess->setType("2");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else{
                    scene->addItem(chess);
                    chess->setPixmap(b1);
                    chess->setOwner("Black");
                    chess->setType("1");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }

            else if(j==2){
                if(i==1 || i==7){
                    scene->addItem(chess);
                    chess->setPixmap(b6);
                    chess->setOwner("Black");
                    chess->setType("6");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }

            else if(j==3){
                if(i==0 || i==2 || i==4 || i==6 || i==8){
                    scene->addItem(chess);
                    chess->setPixmap(b7);
                    chess->setOwner("Black");
                    chess->setType("7");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }

            // RED CHESS
            else if(j==6){
                if(i==0 || i==2 || i==4 || i==6 || i==8){
                    scene->addItem(chess);
                    chess->setPixmap(r7);
                    chess->setOwner("Red");
                    chess->setType("7");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }
            else if(j==7){
                if(i==1 || i==7){
                    scene->addItem(chess);
                    chess->setPixmap(r6);
                    chess->setOwner("Red");
                    chess->setType("6");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }
            else if(j==9){
                if(i==0 || i==8){
                    scene->addItem(chess);
                    chess->setPixmap(r4);
                    chess->setOwner("Red");
                    chess->setType("4");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==1 || i==7){
                    scene->addItem(chess);
                    chess->setPixmap(r5);
                    chess->setOwner("Red");
                    chess->setType("5");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==2 || i==6){
                    scene->addItem(chess);
                    chess->setPixmap(r3);
                    chess->setOwner("Red");
                    chess->setType("3");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else if(i==3 || i==5){
                    scene->addItem(chess);
                    chess->setPixmap(r2);
                    chess->setOwner("Red");
                    chess->setType("2");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
                else{
                    scene->addItem(chess);
                    chess->setPixmap(r1);
                    chess->setOwner("Red");
                    chess->setType("1");
                    chess->setxPos(i);
                    chess->setyPos(j);
                    chessPtr[count++] = chess;
                }
            }
        }
    }
}

void MainWindow::restartGame()
{
    Game();
}

void MainWindow::restartMenu()
{
    displayMainMenu();
}

void MainWindow::changeTurn()
{
    if(whosTurn == "Red"){
        Pointer->setPos(702,275);
        whosTurn = "Black";
    }
    else{
        Pointer->setPos(702,430);
        whosTurn = "Red";
    }
}

void MainWindow::editorToPlay()
{
    mode = "game";
    delete this->remove;
    delete this->change;
    delete this->play;

    // creat Button
    editor = new Button("Editor");
    editor->setFontSize(20);
    int xPos = 975;
    int yPos = 357;
    editor->setPos(xPos,yPos);
    connect(editor,SIGNAL(clicked()),this,SLOT(gameToEditor()));
    scene->addItem(editor);

}

void MainWindow::editorRemove()
{
    QPixmap clear;
    clear.load(":/new/prefix1/clear");
    clear = clear.scaled(2,2,Qt::KeepAspectRatio);
    if(chessToPlace != nullptr){
        chessToPlace->setPixmap(clear);
        chessToPlace->setPos(690,750);
        chessToPlace->setType("Eaten");
        chessToPlace->setxPos(999);
        chessToPlace->setyPos(999);
        chessToPlace = nullptr;
    }
    else{
        qDebug()<<"choose a chess";
    }
}

void MainWindow::gameToEditor()
{
    mode = "editor";

    // creat Button
    remove = new Button("Remove");
    remove->setFontSize(20);
    int xPos = 975;
    int yPos = 282;
    remove->setPos(xPos,yPos);
    connect(remove,SIGNAL(clicked()),this,SLOT(editorRemove()));
    scene->addItem(remove);

    change = new Button("Change Turn");
    change->setFontSize(20);
    int cxPos = 975;
    int cyPos = 357;
    change->setPos(cxPos,cyPos);
    connect(change,SIGNAL(clicked()),this,SLOT(changeTurn()));
    scene->addItem(change);

    play = new Button("Play");
    play->setFontSize(20);
    int pxPos = 975;
    int pyPos = 432;
    play->setPos(pxPos,pyPos);
    connect(play,SIGNAL(clicked()),this,SLOT(editorToPlay()));
    scene->addItem(play);
}

void MainWindow::displayMainMenu()
{
    // clean screen
    scene->clear();
    //creat title
    QGraphicsTextItem *title = new QGraphicsTextItem(QString("Chinese Chess"));
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    int txPos = this->width()/2 - title->boundingRect().width()/2;
    int tyPos = 150;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    // creat play button
    Button *playButton = new Button(QString("Play"));
    playButton->setFontSize(20);
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(Game()));
    scene->addItem(playButton);

    // creat editor mode
    Button *editButton = new Button(QString("Editor"));
    editButton->setFontSize(20);
    int exPos = this->width()/2 - playButton->boundingRect().width()/2;
    int eyPos = 350;
    editButton->setPos(exPos,eyPos);
    connect(editButton,SIGNAL(clicked()),this,SLOT(Editor()));
    scene->addItem(editButton);

    // creat quit button
    Button *quitButton = new Button(QString("Quit"));
    quitButton->setFontSize(20);
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = getRightxPos(event->x()-35);
    int y = getRightyPos(event->y()-35-17);
    if(x==-1||y==-1){
        qDebug()<<"cannot place";
    }

    // Game Mode
    if(chessToPlace && x!=-1 && y!=-1 && mode=="game"){
        if(chessToPlace->checkStep((x-15)/74,(y-15)/74)){
            if(chessToPlace->getxPos() != ((x-15)/74) ){
                if( !(chessToPlace->checkGeneralFaceToFace(chessToPlace->getxPos(),chessToPlace->getyPos())) ){
                    chessToPlace->setPos(x,y);
                    chessToPlace->setxPos((x-15)/74);
                    chessToPlace->setyPos((y-15)/74);
                    chessToPlace = nullptr;
                    nextPlayer();
                }
                else {
                    chessToPlace = nullptr;
                    qDebug()<<"Face to Face";
                }
            }
            else {
                chessToPlace->setPos(x,y);
                chessToPlace->setxPos((x-15)/74);
                chessToPlace->setyPos((y-15)/74);
                chessToPlace = nullptr;
                nextPlayer();
            }
        }
        else{
            chessToPlace = nullptr;
        }

        qDebug()<<getWhosTurn();
    }

    // Editor Mode

    if(chessToPlace && x!=-1 && y!=-1 && mode=="editor"){
            chessToPlace->setPos(x,y);
            chessToPlace->setxPos((x-15)/74);
            chessToPlace->setyPos((y-15)/74);
            chessToPlace = nullptr;
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(chessToPlace){
        chessToPlace->setPos(event->pos());
    }
    //mouseMoveEvent(event);
}

void MainWindow::pickUpChess(Chess *chess)
{
    // Game mode
    if(chess->getOwner()==whosTurn && chessToPlace==nullptr && mode=="game"){
        chessToPlace = chess;
        //originalPos = chess->pos();
        qDebug()<<"picked";
        return;
    }

    // Editor Mode
    if(chessToPlace==nullptr && mode=="editor"){
        chessToPlace = chess;
        //originalPos = chess->pos();
        qDebug()<<"picked";
        return;
    }

}

int MainWindow::getRightxPos(int pos)
{
    for(int i=0;i<9;++i){
        if(pos>=(15+74*i-35) && pos<=(15+74*i+35)){
            return (15+74*i);
        }
    }
    return -1;
}

int MainWindow::getRightyPos(int pos)
{
    for(int i=0;i<10;++i){
        if(pos>=(15+74*i-35) && pos<=(15+74*i+35)){
            return (15+74*i);
        }
    }
    return -1;
}

QString MainWindow::getWhosTurn()
{
    return whosTurn;
}

void MainWindow::nextPlayer()
{
    if(whosTurn == "Red"){
        Pointer->setPos(702,275);
        whosTurn = "Black";
    }
    else{
        Pointer->setPos(702,430);
        whosTurn = "Red";
    }
}

void MainWindow::drawMessageBoard(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem *panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void MainWindow::gameOver(QString winner)
{
    QString message;
    if(winner == "Red"){
        message = "Red has won!!";
    }
    if(winner == "Black"){
        message = "Black has won!!";
    }

    displayGameOverWindow(message);
}

void MainWindow::displayGameOverWindow(QString message)
{
    // disable all scene items
    for(int i=0;i<scene->items().size();++i){
        scene->items()[i]->setEnabled(false);
    }

    // pop up the message
    drawMessageBoard(0,0,scene->width(),scene->height(),Qt::gray,0.65);



    // creat the button
    Button *playAgain = new Button(QString("Play Again"));
    playAgain->setFontSize(20);
    playAgain->setPos(this->width()/2-playAgain->boundingRect().width()/2,375);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    Button *menu = new Button(QString("Back to Menu"));
    menu->setFontSize(20);
    menu->setPos(this->width()/2-menu->boundingRect().width()/2,450);
    scene->addItem(menu);
    connect(menu,SIGNAL(clicked()),this,SLOT(restartMenu()));

    Button *quit = new Button(QString("Quit"));
    quit->setFontSize(20);
    quit->setPos(this->width()/2-quit->boundingRect().width()/2,525);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // creat the message
    QGraphicsTextItem *title = new QGraphicsTextItem(message);
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    title->setPos(this->width()/2 - title->boundingRect().width()/2,250);
    scene->addItem(title);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Game()
{
    mode = "game";

    // clear the screen
    scene->clear();

    // initialize the eaten number
    rEatenNum = 0;
    bEatenNum = 0;

    // creat Button
    editor = new Button("Editor");
    editor->setFontSize(20);
    int xPos = 975;
    int yPos = 357;
    editor->setPos(xPos,yPos);
    connect(editor,SIGNAL(clicked()),this,SLOT(gameToEditor()));
    scene->addItem(editor);



    // creat GUI
    // Red
    QGraphicsTextItem *Red = new QGraphicsTextItem(QString("Red"));
    QFont rFont("comic sans",40);
    Red->setFont(rFont);
    int RxPos = 775;
    int RyPos = 430;
    Red->setPos(RxPos,RyPos);
    scene->addItem(Red);

    // Black
    QGraphicsTextItem *Black = new QGraphicsTextItem(QString("Black"));
    QFont bFont("comic sans",40);
    Black->setFont(bFont);
    int BxPos = 775;
    int ByPos = 275;
    Black->setPos(BxPos,ByPos);
    scene->addItem(Black);

    QPixmap pointer;
    pointer.load(":/new/prefix1/whosturn");
    pointer = pointer.scaled(70,70,Qt::KeepAspectRatio);
    Pointer = new QGraphicsPixmapItem(pointer);
    Pointer->setPos(702,430);
    scene->addItem(Pointer);

    start();
}

void MainWindow::Editor()
{
    mode = "editor";

    // clear the screen
    scene->clear();

    // initialize the eaten number
    rEatenNum = 0;
    bEatenNum = 0;

    // creat Button
    remove = new Button("Remove");
    remove->setFontSize(20);
    int xPos = 975;
    int yPos = 282;
    remove->setPos(xPos,yPos);
    connect(remove,SIGNAL(clicked()),this,SLOT(editorRemove()));
    scene->addItem(remove);

    change = new Button("Change Turn");
    change->setFontSize(20);
    int cxPos = 975;
    int cyPos = 357;
    change->setPos(cxPos,cyPos);
    connect(change,SIGNAL(clicked()),this,SLOT(changeTurn()));
    scene->addItem(change);

    play = new Button("Play");
    play->setFontSize(20);
    int pxPos = 975;
    int pyPos = 432;
    play->setPos(pxPos,pyPos);
    connect(play,SIGNAL(clicked()),this,SLOT(editorToPlay()));
    scene->addItem(play);


    // creat GUI
    // Red
    QGraphicsTextItem *Red = new QGraphicsTextItem(QString("Red"));
    QFont rFont("comic sans",40);
    Red->setFont(rFont);
    int RxPos = 775;
    int RyPos = 430;
    Red->setPos(RxPos,RyPos);
    scene->addItem(Red);

    // Black
    QGraphicsTextItem *Black = new QGraphicsTextItem(QString("Black"));
    QFont bFont("comic sans",40);
    Black->setFont(bFont);
    int BxPos = 775;
    int ByPos = 275;
    Black->setPos(BxPos,ByPos);
    scene->addItem(Black);

    QPixmap pointer;
    pointer.load(":/new/prefix1/whosturn");
    pointer = pointer.scaled(70,70,Qt::KeepAspectRatio);
    Pointer = new QGraphicsPixmapItem(pointer);
    Pointer->setPos(702,430);
    scene->addItem(Pointer);

    start();
}
