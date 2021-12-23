#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EcoVille++");

    m_mainWidget= new QWidget(this);

    m_vLayout=new QVBoxLayout(this);
    m_hLayout=new QHBoxLayout(this);

   // QPushButton* test=new QPushButton("big button",m_mainWidget);
    CustomButton* test=new CustomButton(m_mainWidget);
    connect(test,SIGNAL(clicked(bool)),this,SLOT(DireBonjour(bool)));
    m_hLayout->addItem(m_vLayout);
    m_hLayout->addWidget(test);
    m_mainWidget->setLayout(m_hLayout);

    for(int i=0;i<4;i++){
        CustomButton* btn=new CustomButton(m_mainWidget);
        connect(btn,SIGNAL(clicked(bool)),this,SLOT(DireBonjour(bool)));

        m_listBtn.append(btn);
        m_vLayout->addWidget(btn);
            }

    setCentralWidget(m_mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::DireBonjour(bool b){
    qDebug() <<"Bonjour\n";
}

