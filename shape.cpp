#include "shape.h"

Shape::Shape(QWidget *_parent, int count) : shape("Circle")
{
    // Code to give each item a unique name (part 2)
    QString name;
    name.setNum(count);
    this->setParent(_parent);
    this->setObjectName(name);
}

void Shape::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QColor colorObj(0, 0, 0);

    QBrush brush(colorObj, Qt::SolidPattern);
    painter.begin(this);
    helper.setColor(colorObj);
    painter.setBackground(brush);
    painter.setRenderHint(QPainter::Antialiasing);

    this->helper.paint(&painter, event, &shape);
    painter.end();
}
