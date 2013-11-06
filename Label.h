#ifndef LABEL_H
#define LABEL_H

#include "timer.h"

class Timer;

class Label : public QLabel
{
    enum direction { NORTHEAST, EAST, SOUTHEAST, SOUTHWEST, WEST, NORTHWEST };

    Q_OBJECT

public:
    Label();
    Label(QWidget *parent, QString str);
    void setDirection(int);
    int getDirection();
    Timer *object;

private:
    direction dir;
};

#endif // LABEL_H
