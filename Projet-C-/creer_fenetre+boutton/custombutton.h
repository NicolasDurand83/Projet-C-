#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QObject>

class CustomButton : public QPushButton
{

public:
    CustomButton(QWidget *parent = nullptr);
    ~CustomButton();


};

#endif // CUSTOMBUTTON_H
