#include "mafenetre.h"
#include<QDebug>
void MaFenetre::donner(int i, int j){
     qDebug()<<"position("<<i<<","<<j<<")";
}

MaFenetre::MaFenetre() :QWidget(){
       setWindowTitle(("EcoVille++"));
       QGridLayout *layout_principal = new QGridLayout;
       QGridLayout *layout_achat=new QGridLayout;
       QGridLayout *layout_info=new QGridLayout;
       QGridLayout *layout_jeu=new QGridLayout;
       this->layout_principal=layout_principal;
       this->layout_achat=layout_achat;
       this->layout_info=layout_info;
       this->layout_jeu=layout_jeu;

       layout_principal->addLayout(layout_info,0,0);
       layout_principal->addLayout(layout_jeu,1,0);
       layout_principal->addLayout(layout_achat,2,0);


       QPushButton *bouton1= new QPushButton("Bonjour");
       QPushButton *bouton2 = new QPushButton("les");
       QPushButton *bouton3 = new QPushButton("Zéros");
       layout_achat->addWidget(bouton1, 0, 0);
       layout_achat->addWidget(bouton2, 0, 1);
       layout_achat->addWidget(bouton3, 1, 0,1,2);
       connect(bouton1,SIGNAL(clicked()),this,SLOT(donner(1,1)));
       QPushButton *mapp[10][10];
       for(int i=0;i<10;i++){
           for(int j=0;j<10;j++){
               QPushButton *boutona= new QPushButton;
               mapp[i][j]=boutona;
               //connect(mapp[i][j],SIGNAL(clicked()),this,SLOT(donner(i,j)));
               //connect(&Cathy,SIGNAL(Speak(QString)),&Sally,SLOT(Listen(QString)));//


               layout_jeu->addWidget(mapp[i][j],i,j);
               //*mapp[i][j]=new QPushButton("10");
           }
       }

       QLabel *label_argent=new QLabel("argent");
       layout_info->addWidget(label_argent,0,0);

       QLabel *label_val_argent=new QLabel("0€");
       layout_info->addWidget(label_val_argent,0,1);

        //label->setText("aerazer");


       setLayout(layout_principal);
       /*m_lcd = new QLCDNumber(this);
       m_lcd->setSegmentStyle(QLCDNumber::Flat);
       m_lcd->move(50, 20);

       m_slider = new QSlider(Qt::Horizontal, this);
       m_slider->setGeometry(10, 60, 150, 20);
       QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;*/
   }
