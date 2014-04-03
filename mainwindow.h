#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pion.h"
#include "joueur.h"

namespace Ui {
class MainWindow;
}

/*! \class MainWindow.h
 *  \brief This is the MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    /*!
     * \brief MainWindow
     * \param parent
     */

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    /*!
     * \brief vecteur qui contient les positions possibles sur le plateau
     */
    QVector <QPoint> vPos;

    /*!
     * \brief vecteur qui contient les positions des pions sur le plateau
     *
     */
    QVector <QPoint> vPionPos;

    /*!
     * \brief vecteur qui contient dit si la position est libre ou non.
     *
     *
     * \return vrai si il n'y a pas de pions sur la position et faux si elle est occupé.
     */
    QVector <bool> vPosLibre;

    /*!
     * \brief vecteur qui contient les pions.
     */
    QVector <pion*> vPionPion;

    /*!
     * \brief donne le tour du joueur.
     * \return le numéro du joueur.
     *
     * variable contenant un entier correspondant au numéro du joueur dont c'est le tour.
     *
     */
    int tourDuJoueur=1;

    /*!
     * \brief posOk
     */
    bool posOk;

    /*!
     * \brief toutPlacer
     */
    int toutPlacer=0;

    /*!
     * \brief tousSurLePlateau
     */
    bool tousSurLePlateau;

    /*!
     * \brief coofX
     */
    double coofX; // coefficent de redimentionnement

    /*!
     * \brief coofY
     */
    double coofY;

    /*!
     * \brief suisJeGagnant
     * \param P1
     * \param P2
     * \param P3
     */
    void suisJeGagnant(int P1, int P2, int P3);

    /*!
     * \brief restart
     * \param joueurGagnant
     */
    void restart(int joueurGagnant);

    /*!
     * \brief nouveauJeu
     */
    void nouveauJeu();

private:

    /*!
     * \brief creerPions
     */
    void creerPions();
};

#endif // MAINWINDOW_H
