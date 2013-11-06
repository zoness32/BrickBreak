#ifndef HELPER_H
 #define HELPER_H

 #include <QBrush>
 #include <QFont>
 #include <QPen>
 #include <QRect>

 class QPainter;
 class QPaintEvent;

 class Helper
 {
 public:
     Helper();

 public:
     void paint(QPainter *painter, QPaintEvent *event, QString*);
     void setGeometry(QRect geom);
     void setColor(QColor colors);

 private:
     QBrush background;
     QBrush circleBrush;
     QFont textFont;
     QPen circlePen;
     QPen textPen;

     QRect geometry;
 };

 #endif
