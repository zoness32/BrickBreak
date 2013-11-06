#include "Label.h"

Label::Label() : dir (direction(rand() % 7))
{

}

Label::Label(QWidget *parent, QString str)
{
    if (str == "paddle") dir = EAST;
    else if (str == "ball")
    {
        int i = rand() % 2;
        if (i == 0) dir = NORTHEAST;
        else dir = NORTHWEST;
    }
    this->setParent(parent);
    this->setObjectName(str);
}

void Label::setDirection(int i)
{
    this->dir = (direction)i;
}

int Label::getDirection()
{
    return this->dir;
}
