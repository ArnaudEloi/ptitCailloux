#ifndef JOUEUR_H
#define JOUEUR_H

#include "mainwindow.h"
class Joueur : public QWidget
{
public:
    /*!
     * \brief Joueur
     * \param parent
     */
    explicit Joueur(QWidget *parent = 0);
    /*!
     * \brief suisJeGagnant
     * \param P1
     * \param P2
     * \param P3
     */
    void suisJeGagnant(int P1, int P2, int P3);
};

#endif // JOUEUR_H
