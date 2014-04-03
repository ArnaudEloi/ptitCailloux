/*!
 *  \version 1.0
 *  \brief     Main class
 *  \details   This class make the MainWindow
 *  \author    Arnaud Eloi
 *  \date      2013
 *  \copyright GNU public licence
 */
#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *translator = new QTranslator;
    translator->load("ptitCailloux_fr.qm");

    a.installTranslator(translator);

    MainWindow w;
    w.show();

    return a.exec();
}

