#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gagner.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelTour->setText(tr("It's up to player 1"));

/// ANDROID

#ifdef ANDROID
    qDebug()<<"Android";
QDesktopWidget *mydesk = QApplication::desktop();
// /!\ le jeu étant au format portrait la largeur et la hauteur sont inversé
    double hauteur=mydesk->screenGeometry().width();
    double largeur=mydesk->screenGeometry().height();
    qDebug()<<QString::number(largeur);
    qDebug()<<QString::number(hauteur);
    coofX=hauteur/400.0;
    coofY=largeur/475.0;
    qDebug()<<QString::number(coofX);
    ui->labelTablo->move(0,ui->labelTablo->y()*coofY);
    ui->labelTablo->resize(ui->labelTablo->width()*coofX,ui->labelTablo->height()*coofY);
#endif

/// XXX
    this->creerPions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::suisJeGagnant(int P1, int P2, int P3)
{
    if((this->vPos.at(0).x()==this->vPionPos.at(P1).x() && this->vPos.at(0).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(0).x()==this->vPionPos.at(P2).x() && this->vPos.at(0).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(0).x()==this->vPionPos.at(P3).x() && this->vPos.at(0).y()==this->vPionPos.at(P3).y()))
    {
        if((this->vPos.at(1).x()==this->vPionPos.at(P1).x() && this->vPos.at(1).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(1).x()==this->vPionPos.at(P2).x() && this->vPos.at(1).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(1).x()==this->vPionPos.at(P3).x() && this->vPos.at(1).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(2).x()==this->vPionPos.at(P1).x() && this->vPos.at(2).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P2).x() && this->vPos.at(2).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P3).x() && this->vPos.at(2).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
        if((this->vPos.at(4).x()==this->vPionPos.at(P1).x() && this->vPos.at(4).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P2).x() && this->vPos.at(4).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P3).x() && this->vPos.at(4).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(8).x()==this->vPionPos.at(P1).x() && this->vPos.at(8).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P2).x() && this->vPos.at(8).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P3).x() && this->vPos.at(8).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
        if((this->vPos.at(3).x()==this->vPionPos.at(P1).x() && this->vPos.at(3).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(3).x()==this->vPionPos.at(P2).x() && this->vPos.at(3).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(3).x()==this->vPionPos.at(P3).x() && this->vPos.at(3).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(6).x()==this->vPionPos.at(P1).x() && this->vPos.at(6).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(6).x()==this->vPionPos.at(P2).x() && this->vPos.at(6).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(6).x()==this->vPionPos.at(P3).x() && this->vPos.at(6).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
    }
    if((this->vPos.at(3).x()==this->vPionPos.at(P1).x() && this->vPos.at(3).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(3).x()==this->vPionPos.at(P2).x() && this->vPos.at(3).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(3).x()==this->vPionPos.at(P3).x() && this->vPos.at(3).y()==this->vPionPos.at(P3).y()))
    {
        if((this->vPos.at(4).x()==this->vPionPos.at(P1).x() && this->vPos.at(4).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P2).x() && this->vPos.at(4).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P3).x() && this->vPos.at(4).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(5).x()==this->vPionPos.at(P1).x() && this->vPos.at(5).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(5).x()==this->vPionPos.at(P2).x() && this->vPos.at(5).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(5).x()==this->vPionPos.at(P3).x() && this->vPos.at(5).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
    }
    if((this->vPos.at(6).x()==this->vPionPos.at(P1).x() && this->vPos.at(6).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(6).x()==this->vPionPos.at(P2).x() && this->vPos.at(6).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(6).x()==this->vPionPos.at(P3).x() && this->vPos.at(6).y()==this->vPionPos.at(P3).y()))
    {
        if((this->vPos.at(4).x()==this->vPionPos.at(P1).x() && this->vPos.at(4).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P2).x() && this->vPos.at(4).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P3).x() && this->vPos.at(4).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(2).x()==this->vPionPos.at(P1).x() && this->vPos.at(2).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P2).x() && this->vPos.at(2).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P3).x() && this->vPos.at(2).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
        if((this->vPos.at(7).x()==this->vPionPos.at(P1).x() && this->vPos.at(7).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(7).x()==this->vPionPos.at(P2).x() && this->vPos.at(7).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(7).x()==this->vPionPos.at(P3).x() && this->vPos.at(7).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(8).x()==this->vPionPos.at(P1).x() && this->vPos.at(8).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P2).x() && this->vPos.at(8).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P3).x() && this->vPos.at(8).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
    }
    if((this->vPos.at(1).x()==this->vPionPos.at(P1).x() && this->vPos.at(1).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(1).x()==this->vPionPos.at(P2).x() && this->vPos.at(1).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(1).x()==this->vPionPos.at(P3).x() && this->vPos.at(1).y()==this->vPionPos.at(P3).y()))
    {
        if((this->vPos.at(4).x()==this->vPionPos.at(P1).x() && this->vPos.at(4).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P2).x() && this->vPos.at(4).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(4).x()==this->vPionPos.at(P3).x() && this->vPos.at(4).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(7).x()==this->vPionPos.at(P1).x() && this->vPos.at(7).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(7).x()==this->vPionPos.at(P2).x() && this->vPos.at(7).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(7).x()==this->vPionPos.at(P3).x() && this->vPos.at(7).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
    }
    if((this->vPos.at(2).x()==this->vPionPos.at(P1).x() && this->vPos.at(2).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P2).x() && this->vPos.at(2).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(2).x()==this->vPionPos.at(P3).x() && this->vPos.at(2).y()==this->vPionPos.at(P3).y()))
    {
        if((this->vPos.at(5).x()==this->vPionPos.at(P1).x() && this->vPos.at(5).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(5).x()==this->vPionPos.at(P2).x() && this->vPos.at(5).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(5).x()==this->vPionPos.at(P3).x() && this->vPos.at(5).y()==this->vPionPos.at(P3).y()))
        {
            if((this->vPos.at(8).x()==this->vPionPos.at(P1).x() && this->vPos.at(8).y()==this->vPionPos.at(P1).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P2).x() && this->vPos.at(8).y()==this->vPionPos.at(P2).y()) || (this->vPos.at(8).x()==this->vPionPos.at(P3).x() && this->vPos.at(8).y()==this->vPionPos.at(P3).y()))
            {
                int joueur;
                if(P1==0)
                    joueur=1;
                else
                    joueur=2;

                qDebug()<<tr("WIN ! player : ")<<joueur;
                this->restart(joueur);
            }
        }
    }

}

void MainWindow::restart(int joueurGagnant)
{

    gagner * gg=new gagner(this);
    gg->showNormal();
    gg->activer(joueurGagnant);
}

void MainWindow::nouveauJeu()
{

    toutPlacer=0;
    tousSurLePlateau=false;

    for(int i=0;i<6;i++)
      {
        delete vPionPion.at(i);
      }

    vPionPos.remove(0,6);
    vPosLibre.remove(0,9);

    vPionPion.clear();
    vPionPos.clear();
    vPosLibre.clear();
    this->creerPions();
}

void MainWindow::creerPions()
{
    vPos.push_back(QPoint(53,130));
    vPos.push_back(QPoint(176,126));
    vPos.push_back(QPoint(297,123));

    vPos.push_back(QPoint(37,196));
    vPos.push_back(QPoint(180,190));
    vPos.push_back(QPoint(320,186));

    vPos.push_back(QPoint(16,285));
    vPos.push_back(QPoint(185,279));
    vPos.push_back(QPoint(351,272));

    for(int i=0;i<9;i++)
    {
        vPosLibre.push_back(true);
    }
    int y=(437.5-25);

    vPionPion.push_back(new pion(this,0,20,y));
    vPionPion.push_back(new pion(this,1,80,y));
    vPionPion.push_back(new pion(this,2,140,y));
    vPionPion.push_back(new pion(this,3,210,y));
    vPionPion.push_back(new pion(this,4,270,y));
    vPionPion.push_back(new pion(this,5,330,y));
}




