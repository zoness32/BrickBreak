#ifndef SHAPE_H
#define SHAPE_H

#include <QPushButton>
#include <QMimeData>
#include <QDrag>
#include <QMouseEvent>
#include <QtGui>
#include "helper.h"

class Shape : public QWidget
{
    Q_OBJECT
    public:
        Shape(QWidget *parent, int count = 0);
        QString shape;

    private slots:
        void paintEvent(QPaintEvent *event);

    private:
        Helper helper;
};

#endif // WIDGIE_H
