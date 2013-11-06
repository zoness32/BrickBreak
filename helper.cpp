#include <QtGui>
#include <QPainter>
#include "helper.h"

 Helper::Helper()
 {
     geometry = QRect(0,0,30,30);
 }

 void Helper::setColor(QColor color)
 {
    background.setColor(color);
    circlePen.setColor(color);
 }

 void Helper::setGeometry(QRect _geometry)
 {
    geometry = _geometry;
 }

 void Helper::paint(QPainter *painter, QPaintEvent *event, QString *type)
 {
     background.setStyle(Qt::SolidPattern);
     painter->translate(1, 1);
     painter->save();
     painter->setBrush(circleBrush);
     painter->setPen(circlePen);
     painter->setBackground(background);

     if (type->toAscii() == "Circle")
     {
         painter->drawEllipse(0,0,30,30);

         QPainterPath path = QPainterPath();
         path.addEllipse(geometry);
         painter->fillPath(path, background);

     } else if (type->toAscii() == "Square")
     {
        painter->drawRect(geometry);
        painter->fillRect(geometry, background);
     }
     painter->restore();
 }

