#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include<memory>
#include <QtWidgets>//on touve ans QtWidgets =>Qwidget Qfont QPushButton ...
#include <QFont>
#include <QIcon>

#include <QGridLayout>
class MaFenetre:public QWidget{
public:
    MaFenetre();
private:
    QLCDNumber *m_lcd;//unwidget qui affiche un nombre
    QSlider    *m_slider;//un curseur qui permet de définir une valeur
    QGridLayout *layout_principal;
    QGridLayout *layout_achat;
    QGridLayout *layout_info;
    QGridLayout *layout_jeu;


public slots:
    void donner(int i,int j);

};

#endif // MAFENETRE_H
