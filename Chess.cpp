#include "Chess.h"
#include "mainwindow.h"

extern MainWindow *w;


Chess::Chess()
{
    setAcceptHoverEvents(true);
}

void Chess::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPixmap clear;
    clear.load(":/new/prefix1/clear");
    clear = clear.scaled(2,2,Qt::KeepAspectRatio);

    // pick up the chess
    if(w->chessToPlace == nullptr){
       w->pickUpChess(this);
       qDebug()<<owner<<" "<<type;
       qDebug()<<"("<<xPos<<","<<yPos<<")";
    }

    // eat the chess
    if(w->chessToPlace!=nullptr && w->chessToPlace!=this){
        if(this->owner != w->chessToPlace->owner){
            if( (w->chessToPlace->checkStep(this->getxPos(),this->getyPos())) && (w->chessToPlace->getType()!="6") ){
                if(w->chessToPlace->getxPos() != this->getxPos()) {
                    if(!(w->chessToPlace->checkGeneralFaceToFace(w->chessToPlace->getxPos(),w->chessToPlace->getyPos()))){
                        int x = this->getxPos();
                        int y = this->getyPos();
                        QString iseaten = this->getType();
                        if(this->getOwner()=="Black"){
                            this->setPos(redEatenxPos[w->rEatenNum],redEatenyPos[w->rEatenNum]);
                            this->setEnabled(false);
                            ++w->rEatenNum;
                        }
                        else{
                            this->setPos(blackEatenxPos[w->bEatenNum],blackEatenyPos[w->bEatenNum]);
                            this->setEnabled(false);
                            ++w->bEatenNum;
                        }
                        this->setType("Eaten");
                        this->setxPos(999);
                        this->setyPos(999);
                        w->chessToPlace->setPos(15+74*x,15+74*y);
                        w->chessToPlace->setxPos(x);
                        w->chessToPlace->setyPos(y);
                        w->chessToPlace = nullptr;
                        w->nextPlayer();
                        qDebug()<< w->getWhosTurn();
                        if(iseaten == "1"){
                            w->nextPlayer();
                            w->gameOver(w->getWhosTurn());
                        }
                    }
                    else {
                        w->chessToPlace = nullptr;
                    }
                }
                else{
                    int x = this->getxPos();
                    int y = this->getyPos();
                    QString iseaten = this->getType();
                    //this->setPixmap(clear);
                    if(this->getOwner()=="Black"){
                        this->setPos(redEatenxPos[w->rEatenNum],redEatenyPos[w->rEatenNum]);
                        this->setEnabled(false);
                        ++w->rEatenNum;
                    }
                    else{
                        this->setPos(blackEatenxPos[w->bEatenNum],blackEatenyPos[w->bEatenNum]);
                        this->setEnabled(false);
                        ++w->bEatenNum;
                    }
                    this->setType("Eaten");
                    this->setxPos(999);
                    this->setyPos(999);
                    w->chessToPlace->setPos(15+74*x,15+74*y);
                    w->chessToPlace->setxPos(x);
                    w->chessToPlace->setyPos(y);
                    w->chessToPlace = nullptr;
                    w->nextPlayer();
                    qDebug()<< w->getWhosTurn();
                    if(iseaten == "1"){
                        w->nextPlayer();
                        w->gameOver(w->getWhosTurn());
                    }
                }

            }
            // pao eat condition
            else if( (w->chessToPlace->getType()=="6") && (w->chessToPlace->checkPaoEatStep(this->getxPos(),this->getyPos())) ){
                if(w->chessToPlace->getxPos() != this->getxPos()) {
                    if(!(w->chessToPlace->checkGeneralFaceToFace(w->chessToPlace->getxPos(),w->chessToPlace->getyPos()))){
                        int x = this->getxPos();
                        int y = this->getyPos();
                        QString iseaten = this->getType();
                        if(this->getOwner()=="Black"){
                            this->setPos(redEatenxPos[w->rEatenNum],redEatenyPos[w->rEatenNum]);
                            this->setEnabled(false);
                            ++w->rEatenNum;
                        }
                        else{
                            this->setPos(blackEatenxPos[w->bEatenNum],blackEatenyPos[w->bEatenNum]);
                            this->setEnabled(false);
                            ++w->bEatenNum;
                        }
                        this->setType("Eaten");
                        this->setxPos(999);
                        this->setyPos(999);
                        w->chessToPlace->setPos(15+74*x,15+74*y);
                        w->chessToPlace->setxPos(x);
                        w->chessToPlace->setyPos(y);
                        w->chessToPlace = nullptr;
                        w->nextPlayer();
                        qDebug()<< w->getWhosTurn();
                        if(iseaten == "1"){
                            w->nextPlayer();
                            w->gameOver(w->getWhosTurn());
                        }
                    }
                    else {
                        w->chessToPlace = nullptr;
                    }
                }
                else{
                    int x = this->getxPos();
                    int y = this->getyPos();
                    QString iseaten = this->getType();
                    if(this->getOwner()=="Black"){
                        this->setPos(redEatenxPos[w->rEatenNum],redEatenyPos[w->rEatenNum]);
                        this->setEnabled(false);
                        ++w->rEatenNum;
                    }
                    else{
                        this->setPos(blackEatenxPos[w->bEatenNum],blackEatenyPos[w->bEatenNum]);
                        this->setEnabled(false);
                        ++w->bEatenNum;
                    }
                    this->setType("Eaten");
                    this->setxPos(999);
                    this->setyPos(999);
                    w->chessToPlace->setPos(15+74*x,15+74*y);
                    w->chessToPlace->setxPos(x);
                    w->chessToPlace->setyPos(y);
                    w->chessToPlace = nullptr;
                    w->nextPlayer();
                    qDebug()<< w->getWhosTurn();
                    if(iseaten == "1"){
                        w->nextPlayer();
                        w->gameOver(w->getWhosTurn());
                    }
                }
            }
            else {
                w->chessToPlace = nullptr;
                qDebug()<< "123";
            }
        }
        else{
            w->chessToPlace = nullptr;
            qDebug()<< w->getWhosTurn();
        }
    }



}

void Chess::setOwner(QString player)
{
    owner = player;
}

void Chess::setType(QString chessType)
{
    type = chessType;
}

void Chess::setxPos(int x)
{
    xPos = x;
}

void Chess::setyPos(int y)
{
    yPos = y;
}

bool Chess::checkStep(int x, int y)
{
    // Jiang&Shuai

    if(this->type == "1"){
        // check if in the square
        if(this->getOwner()=="Black"){
            if(x<3 || x>5 || y<0 || y>2)
                return false;
        }
        if(this->getOwner()=="Red"){
            if(x<3 || x>5 || y<7 || y>9)
                return false;
        }

        // check step
        if(this->getxPos()-x==0){
            if( (this->getyPos()-y==1) ||(this->getyPos()-y==-1) )
                return true;
        }
        else if(this->getyPos()-y==0){
            if( (this->getxPos()-x==1) ||(this->getxPos()-x==-1) )
                return true;
        }
        else {
            return false;
        }
    }

    // Shi
    if(this->type == "2"){
        // check if in the square
        if(this->getOwner()=="Black"){
            if(x<3 || x>5 || y<0 || y>2)
                return false;
        }
        if(this->getOwner()=="Red"){
            if(x<3 || x>5 || y<7 || y>9)
                return false;
        }

        // check step
        if(this->getxPos()-x==1){
            if( (this->getyPos()-y==1) ||(this->getyPos()-y==-1) )
                return true;
        }
        else if (this->getxPos()-x==-1) {
            if( (this->getyPos()-y==1) ||(this->getyPos()-y==-1) )
                return true;
        }
        else {
            return false;
        }
    }


    // Xiang
    if(this->type=="3"){
        // check if cross the river
        if(this->getOwner()=="Black"){
            if(y<0 || y>4)
                return false;
        }
        if(this->getOwner()=="Red"){
            if(y<5 || y>9)
                return false;
        }

        // check step(blocking the elephant's eye)
        if(this->getxPos()-x==2){
            if( (this->getyPos()-y==2) && !(checkHasChess(x+1,y+1))){
                return true;
            }
            else if(this->getyPos()-y==-2 && !(checkHasChess(x+1,y-1))){
                return true;
            }
            else {
                if(checkHasChess(x+1,y+1)||(checkHasChess(x+1,y-1)))
                    qDebug()<<"blocking the elephant's eye";
                return false;
            }
        }
        else if(this->getxPos()-x==-2){
            if( (this->getyPos()-y==2) && !(checkHasChess(x-1,y+1))){
                return true;
            }
            else if(this->getyPos()-y==-2 && !(checkHasChess(x-1,y-1))){
                return true;
            }
            else {
                if((checkHasChess(x-1,y+1))||(checkHasChess(x-1,y-1)))
                    qDebug()<<"blocking the elephant's eye";
                return false;
            }
        }
        else {
            return false;
        }
    }

    // Ju
    if(this->type == "4"){
        // check step(can only go straight)
        if(this->getxPos()-x!=0){
            if(this->getyPos()-y==0){
                if(this->getxPos()>x){
                    int count=0;
                    for(int i=x+1;i<this->getxPos();++i){
                        if(checkHasChess(i,y))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
                else{
                    int count=0;
                    for(int i=this->getxPos()+1;i<x;++i){
                        if(checkHasChess(i,y))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
        }
        else{
            if(this->getyPos()-y!=0)
                if(this->getyPos()>y){
                    int count=0;
                    for(int i=y+1;i<this->getyPos();++i){
                        if(checkHasChess(x,i))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
                else{
                    int count=0;
                    for(int i=this->getyPos()+1;i<y;++i){
                        if(checkHasChess(x,i))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
            else {
                return false;
            }
        }
    }

    // Ma
    if(this->type == "5"){
        // check step(hobbling the horse's leg)
        if( (this->getxPos()-x==1) || (this->getxPos()-x==-1) ){
            if(this->getyPos()-y==2 && !(checkHasChess(this->getxPos(),this->getyPos()-1)) ){
                return true;
            }
            else if( (this->getyPos()-y==-2) && !(checkHasChess(this->getxPos(),this->getyPos()+1)) ){
                return true;
            }
            else {
                if( (checkHasChess(this->getxPos(),this->getyPos()-1)) || (checkHasChess(this->getxPos(),this->getyPos()+1)) )
                    qDebug()<<"hobbling the horse's leg";
                return false;
            }
        }
        else if( (this->getyPos()-y==1) || (this->getyPos()-y==-1) ){
            if( (this->getxPos()-x==2) && !(checkHasChess(this->getxPos()-1,this->getyPos())) ){
                return true;
            }
            else if( (this->getxPos()-x==-2) && !(checkHasChess(this->getxPos()+1,this->getyPos())) ){
                return true;
            }
            else {
                if( (checkHasChess(this->getxPos()-1,this->getyPos())) || (checkHasChess(this->getxPos()+1,this->getyPos())) )
                    qDebug()<<"hobbling the horse's leg";
                return false;
            }
        }
        else {
            return false;
        }
    }


    // pao
    if(this->type == "6"){
        // check step(can only go straight)
        if(this->getxPos()-x!=0){
            if(this->getyPos()-y==0){
                if(this->getxPos()>x){
                    int count=0;
                    for(int i=x+1;i<this->getxPos();++i){
                        if(checkHasChess(i,y))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
                else{
                    int count=0;
                    for(int i=this->getxPos()+1;i<x;++i){
                        if(checkHasChess(i,y))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
        }
        else{
            if(this->getyPos()-y!=0)
                if(this->getyPos()>y){
                    int count=0;
                    for(int i=y+1;i<this->getyPos();++i){
                        if(checkHasChess(x,i))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
                else{
                    int count=0;
                    for(int i=this->getyPos()+1;i<y;++i){
                        if(checkHasChess(x,i))
                            ++count;
                    }
                    if(count==0)
                        return true;
                    else {
                        return false;
                    }
                }
            else {
                return false;
            }
        }
    }

    // Zu&Bing
    if(this->type == "7"){
        // if don't cross the river, it can only go forward
        if(this->getOwner()=="Black"){
            if(this->getyPos()<=4){
                if(this->getxPos()==x){
                    if(this->getyPos()-y==-1)
                        return true;
                }
                else {
                    return false;
                }
            }
        }
        if(this->getOwner()=="Red"){
            if(this->getyPos()>=5){
                if(this->getxPos()==x){
                    if(this->getyPos()-y==1)
                        return true;
                }
                else {
                    return false;
                }
            }
        }

        // if cross the river, it can also go left and right
        if(this->getOwner()=="Black"){
            if(this->getyPos()>4){
                if(this->getxPos()==x){
                    if(this->getyPos()-y==-1)
                        return true;
                }
                else if(this->getyPos()==y){
                    if( (this->getxPos()-x==1) || (this->getxPos()-x==-1) )
                        return true;
                }
                else {
                    return false;
                }
            }
        }
        if(this->getOwner()=="Red"){
            if(this->getyPos()<5){
                if(this->getxPos()==x){
                    if(this->getyPos()-y==1)
                        return true;
                }
                else if(this->getyPos()==y){
                    if( (this->getxPos()-x==1) || (this->getxPos()-x==-1) ){
                        return true;
                    }
                }
                else {
                    return false;
                }
            }
        }

    }
    return false;
}

bool Chess::checkHasChess(int x, int y)
{
    int chessX,chessY;
    for(int i=0;i<32;++i){
        chessX = w->chessPtr[i]->getxPos();
        chessY = w->chessPtr[i]->getyPos();
        if(x==chessX && y==chessY)
            return true;
    }
    return false;
}

bool Chess::checkPaoEatStep(int x, int y)
{
    // count the number of chesses between two cheeses
    int count = 0;
    if(this->getxPos()==x){
        if(this->getyPos()>y){
            for(int i=y+1;i<this->getyPos();++i){
                if(checkHasChess(x,i))
                    ++count;
            }
        }
        else if(this->getyPos()<y){
            for(int i=this->getyPos()+1;i<y;++i){
                if(checkHasChess(x,i))
                    ++count;
            }
        }
        else {
            return false;
        }
    }
    else if(this->getyPos()==y){
        if(this->getxPos()>x){
            for(int i=x+1;i<this->getxPos();++i){
                if(checkHasChess(i,y))
                    ++count;
            }
        }
        else if(this->getxPos()<x){
            for(int i=this->getxPos()+1;i<x;++i){
                if(checkHasChess(i,y))
                    ++count;
            }
        }
        else {
            return false;
        }
    }

    // if there is one chess between two, allow it to eat
    if(count==1){
        return true;
    }
    else {
        return false;
    }

}

bool Chess::checkGeneralFaceToFace(int x,int y)
{
    // load the coordinate about Jiang&Shuai
    int JiangX=-1,ShuaiX=-2,JiangY=-3,ShuaiY=-4;
    for(int i=0;i<32;++i){
        if(w->chessPtr[i]->getOwner()=="Black" && w->chessPtr[i]->getType()=="1"){
            JiangX = w->chessPtr[i]->getxPos();
            JiangY = w->chessPtr[i]->getyPos();
        }
        else if(w->chessPtr[i]->getOwner()=="Red" && w->chessPtr[i]->getType()=="1"){
            ShuaiX = w->chessPtr[i]->getxPos();
            ShuaiY = w->chessPtr[i]->getyPos();
        }
    }

    // check if face to face
    if(JiangX==ShuaiX && JiangX==x){
        for(int i=JiangY+1;i<ShuaiY;++i){
            if(checkHasChess(JiangX,i) && i!=y)
                return false;
        }
    }
    else {
        return false;
    }
    return true;
}

QString Chess::getOwner()
{
    return owner;
}

QString Chess::getType()
{
    return type;
}

int Chess::getxPos()
{
    return xPos;
}

int Chess::getyPos()
{
    return yPos;
}
