#ifndef PION_H
#define PION_H

#include <QLabel>
class pion : public QLabel
{
    Q_OBJECT
public:
    /*!
     * \brief pion
     * \param parent
     * \param noPion
     * \param x
     * \param y
     */
    explicit pion(QWidget *parent = 0, int noPion = 0,int x=50, int y=50);

signals:

public slots:

private:
    /*!
     * \brief mousePressEvent
     * \param ev
     */
    void mousePressEvent(QMouseEvent *ev);
    /*!
     * \brief mouseMoveEvent
     * \param ev
     */
    void mouseMoveEvent(QMouseEvent *ev);
    /*!
     * \brief mouseReleaseEvent
     * \param ev
     */
    void mouseReleaseEvent(QMouseEvent *ev);
    /*!
     * \brief oldX
     */
    int oldX;
    /*!
     * \brief oldY
     */
    int oldY;
    /*!
     * \brief pionNum
     */
    int pionNum;
    /*!
     * \brief bonPoint
     */
    QPoint bonPoint;
    /*!
     * \brief droits
     * \param indice
     */
    void droits(int indice);
    /*!
     * \brief aLeDroit
     */
    bool aLeDroit;
    /*!
     * \brief w
     */
    int w=35;
    /*!
     * \brief h
     */
    int h=40;

};

#endif // PION_H
