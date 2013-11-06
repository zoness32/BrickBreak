#ifndef NEW_TIMER_H
#define NEW_TIMER_H

#include <QTimer>
#include <QDrag>
#include <QtWidgets/QPushButton>
#include <QtWidgets>
#include <QMimeData>
#include "Label.h"
#include "gamescreen.h"

class Label;

namespace Ui {
    class GameScreen;
}

class Timer : public QTimer
{
    Q_OBJECT

    enum direction { NORTHEAST, EAST, SOUTHEAST, SOUTHWEST, WEST, NORTHWEST };

    public:
        Timer(QObject*, QString);
        Timer(QObject*, int, QFrame*);
        QWidget *object;

        int width;
        int x;
        int y;
        int direction;
        void setActive(bool);

signals:
        void eventTriggered(QString);
        void lifeLost();
        void gameWon();

    private slots:
        void edgeDetect();
        void shiftPaddle();
        void writeEvent(QString);

    private:
        int paddleDir, safeX, safeY, menuBarH, ballDir;
        Label *ballCopy;
        QMainWindow *windowCopy;
        QFrame *rightLine;
        QPoint paddleLoc, ballLoc;
        static bool btnDeleted;
        static int loopCount;
        bool blockHit;
};

#endif // NEW_TIMER_H
