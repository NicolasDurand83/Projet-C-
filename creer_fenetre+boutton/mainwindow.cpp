#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("EcoVille++");
    m_btnBonjour=new QPushButton(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

