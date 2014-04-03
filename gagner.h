#ifndef GAGNER_H
#define GAGNER_H

#include <QWidget>

namespace Ui {
class gagner;
}

class gagner : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief gagner
     * \param parent
     */
    explicit gagner(QWidget *parent = 0);
    ~gagner();
    /*!
     * \brief activer
     * \param joueurGagnant
     */
    void activer(int joueurGagnant);

private slots:
    /*!
     * \brief on_pushButtonMerci_clicked
     */
    void on_pushButtonMerci_clicked();

private:
    /*!
     * \brief ui
     */
    Ui::gagner *ui;

};

#endif // GAGNER_H
