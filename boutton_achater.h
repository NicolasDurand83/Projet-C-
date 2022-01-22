#ifndef BOUTTON_ACHATER_H
#define BOUTTON_ACHATER_H

#include <QObject>
#include <QPushButton>
class boutton_achater : public QObject, public QPushButton
{
    Q_OBJECT
public:
    explicit boutton_achater(QObject *parent = nullptr);
    int get_i(){return i;};
    int get_j(){return j;};
private:
    int i;
    int j;
signals:

};

#endif // BOUTTON_ACHATER_H
