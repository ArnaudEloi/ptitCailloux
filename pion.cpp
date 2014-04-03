#include "pion.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include "mainwindow.h"
#include "joueur.h"
pion::pion(QWidget *parent, int noPion, int x, int y) :
    QLabel(parent)
{
    pionNum=noPion;
    ((MainWindow*)parent)->vPionPos.push_back(QPoint(x,y));
                qDebug()<<"Taille de vPionPos (normal=6) : "+QString::number(((MainWindow*)parent)->vPionPos.size());
                qDebug()<<"Taille de vPionPion : "+QString::number(((MainWindow*)parent)->vPionPion.size());
                qDebug()<<QString::number(noPion);
    // placement des pions dessous le plateau en début de partie
    if(noPion<3)
    {
        setPixmap(QPixmap(":/pions/P1d"));
    }
    else
    {
        setPixmap(QPixmap(":/pions/P2d"));
    }
    setStyleSheet("border-image: no-image;");
    setGeometry(x,y,w,h);
    setScaledContents(true);
}

void pion::mousePressEvent(QMouseEvent *ev)
{
//qDebug()<<"tour de "+QString::number(((MainWindow*)parent())->tourDuJoueur);
           // sauvegarde de la position avant le mouvement
           oldX= this->x();
           oldY= this->y();
    qDebug()<<QString::number(((MainWindow*)parent())->toutPlacer);
}

void pion::mouseMoveEvent(QMouseEvent *ev)
{
    // si c'est le tour du joueur 1
    if(((MainWindow*)parent())->tourDuJoueur==1)
    {
        // choix d'un pion
        if(pionNum<3) //si le pion est au joueur 1
        {
            if(((MainWindow*)parent())->toutPlacer<6)
            {
                if(oldY==412)
                {
                    // le pions prend la position de la souris
                    this->move(mapToParent(QPoint(ev->x()-25,ev->y()-25)));
                    setPixmap(QPixmap(":/pions/P1d"));
                }
                else
                {
                    ((MainWindow*)parent())->tousSurLePlateau=false;
                }
            }
            else
            {
                // le pions prend la position de la souris
                this->move(mapToParent(QPoint(ev->x()-25,ev->y()-25)));
                setPixmap(QPixmap(":/pions/P1d"));
                ((MainWindow*)parent())->tousSurLePlateau=true;
            }
        }
    }
    // si c'est le tour du joueur 2
    else
    {
        // choix d'un pion
        if(pionNum>2) //si le pion est au joueur 2
        {
            if(((MainWindow*)parent())->toutPlacer<6)
            {
                if(oldY==412)
                {
                    // le pions prend la position de la souris
                    this->move(mapToParent(QPoint(ev->x()-25,ev->y()-25)));
                    setPixmap(QPixmap(":/pions/P2d"));
                }
                else
                {
                    ((MainWindow*)parent())->tousSurLePlateau=false;
                    qDebug()<<"PLACE TES PIONS !";
                }
            }
            else
            {
                // le pions prend la position de la souris
                this->move(mapToParent(QPoint(ev->x()-25,ev->y()-25)));
                setPixmap(QPixmap(":/pions/P2d"));
                ((MainWindow*)parent())->tousSurLePlateau=true;
            }
        }
    }
}

void pion::mouseReleaseEvent(QMouseEvent *ev)
{
    ((MainWindow*)parent())->posOk=false;

    // si la souris est dans une zone de drop qui n'est pas occupé
    for(int indice=0;indice<9;indice++)
    {
        int pointPosX=((MainWindow*)parent())->vPos.at(indice).x();
        int pointPosY=((MainWindow*)parent())->vPos.at(indice).y();
        int sourisPosX=mapToParent(ev->pos()).x();
        int sourisPosY=mapToParent(ev->pos()).y();
        int diffX=pointPosX-sourisPosX;
        int diffY=pointPosY-sourisPosY;
        bool libre=((MainWindow*)parent())->vPosLibre.at(indice);
        // si la souris est dans la zone autour du point
        if(diffX<0) diffX=diffX*(-1);
        if(diffY<0) diffY=diffY*(-1);
        // vérification des droits
        this->droits(indice);

        if((((MainWindow*)parent())->tourDuJoueur==1 && pionNum<3) || (((MainWindow*)parent())->tourDuJoueur==2 && pionNum>2))
        {
//            qDebug()<<"diffX(<50) : "+QString::number(diffX);
//            qDebug()<<"diffY(<50) : "+QString::number(diffY);
//            qDebug()<<"tous sur le plateau : "+QString::number(((MainWindow*)parent())->tousSurLePlateau);
//            qDebug()<<"a le droit : "+QString::number(aLeDroit);
//            qDebug()<<"Libre : "+QString::number(libre);

            if(diffX<30 && diffY<30 && libre && aLeDroit && ((MainWindow*)parent())->tousSurLePlateau)
            {
                ((MainWindow*)parent())->posOk=true;
                // placement du pion sur la nouvelle position
                bonPoint.setX(pointPosX);
                bonPoint.setY(pointPosY);
///XXX
                // enregistre la position du point
                ((MainWindow*)parent())->vPionPos.replace(pionNum,QPoint(pointPosX,pointPosY));
                qDebug()<<"Taille de vPionPos (normal=6 ou 5 je sais pas) : "+QString::number(((MainWindow*)parent())->vPionPos.size());



                // la position n'est plus libre
                ((MainWindow*)parent())->vPosLibre.replace(indice,false);

                // réccupération del'ancienne position
                for(int oldIndice=0;oldIndice<9;oldIndice++)
                {
                    int oldPosX=((MainWindow*)parent())->vPos.at(oldIndice).x();
                    int oldPosY=((MainWindow*)parent())->vPos.at(oldIndice).y();
                    if(oldPosX==oldX && oldPosY==oldY)
                    {
                        // l'ancienne position retrouve sa liberté
                        ((MainWindow*)parent())->vPosLibre.replace(oldIndice,true);
                    }
                }
            }
        }
    }
    if(((MainWindow*)parent())->posOk)
    {
        qDebug()<<"bonne position";
       // qDebug()<<"tourDuJoueur passe de"+QString::number(((MainWindow*)parent())->tourDuJoueur);
        // positionnement du pion
        this->move(bonPoint);

        // fin du tour
        if(((MainWindow*)parent())->tourDuJoueur==1)
        {
            ((MainWindow*)parent())->suisJeGagnant(0,1,2);
            ((MainWindow*)parent())->tourDuJoueur=2;
            ((MainWindow*)parent())->ui->labelTour->setText(tr("It's up to player 2"));
        }
        else
        {
            ((MainWindow*)parent())->suisJeGagnant(3,4,5);
            ((MainWindow*)parent())->tourDuJoueur=1;
            ((MainWindow*)parent())->ui->labelTour->setText(tr("It's up to player 1"));
        }
       // qDebug()<<" à "+QString::number(((MainWindow*)parent())->tourDuJoueur);

        if(pionNum<3)
        {
            setPixmap(QPixmap(":/pions/P1g"));
        }
        else
        {
            setPixmap(QPixmap(":/pions/P2g"));
        }

        if(((MainWindow*)parent())->toutPlacer<6) ((MainWindow*)parent())->toutPlacer++;
    }
    else
    {
        // positionnement annulé
       this->move(oldX,oldY);
        qDebug()<<"mauvaise position";
        if(oldY!=412)
        {
            if(pionNum<3)
            {
                setPixmap(QPixmap(":/pions/P1g"));
            }
            else
            {
                setPixmap(QPixmap(":/pions/P2g"));
            }
        }
    }
}

void pion::droits(int indice)
{
    if(oldY==412)// pas encore sur le plateau
    {
        aLeDroit=true;
    }
    else
    {
        // réccupération del'ancienne position
        for(int oldIndice=0;oldIndice<9;oldIndice++)
        {
            int oldPosX=((MainWindow*)parent())->vPos.at(oldIndice).x();
            int oldPosY=((MainWindow*)parent())->vPos.at(oldIndice).y();
            if(oldPosX==oldX && oldPosY==oldY)
            {
                if(oldIndice==0)//si position 1
                {
                    if(indice==1 || indice==3 || indice==4)// ok pour position 2,4 ou 5
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==1)
                {
                    if(indice==0 || indice==4 || indice==2)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==2)
                {
                    if(indice==1 || indice==4 || indice==5)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==3)
                {
                    if(indice==0 || indice==4 || indice==6)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==5)
                {
                    if(indice==2 || indice==4 || indice==8)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==6)
                {
                    if(indice==3 || indice==4 || indice==7)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==7)
                {
                    if(indice==6 || indice==4 || indice==8)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==8)
                {
                    if(indice==7 || indice==4 || indice==5)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

                if(oldIndice==4)
                {
                    if(indice==0 || indice==1 || indice==2 || indice==3 || indice==5 || indice==6 || indice==7 || indice==8)
                        aLeDroit=true;
                    else
                        aLeDroit=false;
                }

            }
        }
    }
}


