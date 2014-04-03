#include "joueur.h"
#include "pion.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

Joueur::Joueur(QWidget *parent)
{
}

void Joueur::suisJeGagnant(int P1, int P2, int P3)
{
    qDebug()<<"P1 = "+QString::number(P1);
    qDebug()<<"((MainWindow*)parent()) : "+QString::number(((MainWindow*)parent())->posOk);
    qDebug()<<"vPionPos size = "+QString::number(((MainWindow*)parent())->vPionPos.size());
        qDebug()<<"vPionPos.at(P1) "+QString::number(((MainWindow*)parent())->vPionPos.at(P1).x());



    // si un des pions est à la position à l'indice 1
//    if((((MainWindow*)parent())->vPos.at(0).x()==((MainWindow*)parent())->vPionPos.at(P1).x() && ((MainWindow*)parent())->vPos.at(0).y()==((MainWindow*)parent())->vPionPos.at(P1).y()) || (((MainWindow*)parent())->vPos.at(0).x()==((MainWindow*)parent())->vPionPos.at(P2).x() && ((MainWindow*)parent())->vPos.at(0).y()==((MainWindow*)parent())->vPionPos.at(P2).y()) || (((MainWindow*)parent())->vPos.at(0).x()==((MainWindow*)parent())->vPionPos.at(P3).x() && ((MainWindow*)parent())->vPos.at(0).y()==((MainWindow*)parent())->vPionPos.at(P3).y()))
//    {
//        qDebug()<<"D'ACCORD";
//    }
}
