#include "mainwindow.h"
/*
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>//on touve ans QtWidgets =>Qwidget Qfont QPushButton ...
#include <QFont>
#include <QIcon>

#include "mafenetre.h"
#include <QGridLayout>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MaFenetre fenetre;

    fenetre.show();

    return app.exec();
}
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MaFenetre fenetre;
    fenetre.show();

    return app.exec();
}*/
/*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Création d'un widget qui servira de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(300, 150);

    // Création du bouton, ayant pour parent la "fenêtre"
    QPushButton bouton("Pimp mon bouton !", &fenetre);
    // Personnalisation du bouton
    bouton.setFont(QFont("Comic Sans MS", 14));
    bouton.setCursor(Qt::PointingHandCursor);
    //dans linux il ne trouve pas l'image mais ca nous aide apres
    bouton.setIcon(QIcon("smile.png"));

    // Affichage de la fenêtre
    fenetre.show();

    return app.exec();
}
*/
