#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>
#include<custombutton.h>
#include<QVBoxLayout>
#include<QHBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void DireBonjour(bool b);

private:
    Ui::MainWindow *ui;
    CustomButton* m_customBtnBonjour;
    QVBoxLayout* m_vLayout;
    QHBoxLayout* m_hLayout;
    QList<CustomButton *> m_listBtn;
    QWidget* m_mainWidget;
};
#endif // MAINWINDOW_H
