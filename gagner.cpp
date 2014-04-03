#include "gagner.h"
#include "ui_gagner.h"
#include "mainwindow.h"
#include <QMovie>
#include <QDebug>

gagner::gagner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gagner)
{
    ui->setupUi(this);
}

gagner::~gagner()
{
    delete ui;
}

void gagner::activer(int joueurGagnant)
{
    qDebug()<<"poc";
    // On crée une vidéo. Ici, c'est un GIF
    QMovie * movie=new QMovie(":/msg/win1.gif");
    // On l'associe à un label
    ui->labelOvation->setMovie(movie);
    ui->label->setText(tr("THE PLAYER ")+QString::number(joueurGagnant)+tr(" IS THE WINNER !"));
    // On lance la vidéo
    movie->start();
}

void gagner::on_pushButtonMerci_clicked()
{
    ((MainWindow *)parent())->nouveauJeu();
    this->close();
}
