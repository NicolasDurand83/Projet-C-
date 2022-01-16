#include "custombutton.h"
#include<QtDebug> //pour faire du debug avecdes printf
CustomButton::CustomButton(QWidget *parent)
    :QPushButton(parent)
{
    setText("firas");
    //setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

}

CustomButton::~CustomButton(){
    qDebug()<< "Destruction\n";
}
