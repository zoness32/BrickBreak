#include <QTimer>
#include <QMouseEvent>
#include "timer.h"

bool Timer::btnDeleted = false;
int Timer::loopCount = 0;

Timer::Timer(QObject *_parent, int count, QFrame *line)
{
    rightLine = new QFrame(line);
    this->setObjectName(QString::number(count));
    this->setParent(_parent);
}

Timer::Timer(QObject *_parent, QString name)
{
    this->setParent(_parent);
    this->setObjectName(name);
    if (name == "ball") connect(this, SIGNAL(timeout()), this, SLOT(edgeDetect()));

    connect(this, SIGNAL(eventTriggered(QString)), this, SLOT(writeEvent(QString)));
}

void Timer::shiftPaddle()
{
    GameScreen *windowCopy = dynamic_cast<GameScreen*>(this->object->parent());
    Label *ball = windowCopy->findChild<Label*>("ball");
    Label *paddle = dynamic_cast<Label*>(this->object);
    paddleLoc = paddle->pos();
    paddleDir = paddle->getDirection();
    ballLoc = ball->pos();
    ballDir = ball->getDirection();
    safeX = 300 - paddle->width();

    switch(paddleDir)
    {
    case EAST:
        if (paddleLoc.x() + 1 < safeX + 1)
        {
            paddleLoc.setX(paddleLoc.x() + 1);
            if (!windowCopy->getSpacePressed()) ballLoc.setX(ballLoc.x() + 1);
        }
        break;
    case WEST:
        if (paddleLoc.x() - 1 >= 0) paddleLoc.setX(paddleLoc.x() - 1);
        if (!windowCopy->getSpacePressed()) ballLoc.setX(ballLoc.x() - 1);
        break;
    }

    paddle->move(paddleLoc.x(), paddleLoc.y());
    ball->move(ballLoc.x(), ballLoc.y());
}

void Timer::edgeDetect()
{
    QMainWindow *window = dynamic_cast<QMainWindow*>(this->object->parent());
    QList<QPushButton*> buttonList = window->findChildren<QPushButton*>("block");

    if (buttonList.count() == 0) emit(gameWon());
    else
    {
        Label *ball = window->findChild<Label*>("ball");
        QPushButton *block;
        Label *paddle = window->findChild<Label*>("paddle");

        int ballLeft, ballRight, ballBtm, ballY, blockLeft, blockRight, blockBtm, blockY, paddleLeft, paddleRight;

        ballLeft = ball->pos().x();
        ballRight = ball->pos().x() + 16;
        ballBtm = ball->pos().y() + 16;
        ballY = ball->pos().y();

        paddleLeft = paddle->pos().x();
        paddleRight = paddle->pos().x() + paddle->width();

        if (ballBtm == paddle->pos().y() && (((ballLeft < paddleLeft && paddleLeft < ballRight) || (ballLeft < paddleRight && paddleRight < ballRight))))
        {
            switch(ball->getDirection())
            {
            case SOUTHWEST:
                ball->setDirection(NORTHEAST);
                emit(eventTriggered("Ball hit edge of paddle"));
                break;
            case SOUTHEAST:
                ball->setDirection(NORTHWEST);
                emit(eventTriggered("Ball hit edge of paddle"));
                break;
            }

        }
        else if (ballBtm == paddle->pos().y() && (ballLeft > paddleLeft && ballRight < paddleRight))
        {
            switch(ball->getDirection())
            {
            case SOUTHWEST:
                ball->setDirection(NORTHWEST);
                emit(eventTriggered("Ball hit middle of paddle"));
                break;
            case SOUTHEAST:
                ball->setDirection(NORTHEAST);
                emit(eventTriggered("Ball hit middle of paddle"));
                break;
            }

        }
        else if (buttonList.count() != 0)
        {
            for (int j = 0; j < buttonList.count() && !blockHit; j++)
            {
                block = buttonList[j];

                blockLeft = block->pos().x();
                blockRight = block->pos().x() + block->width();
                blockBtm = block->pos().y() + block->height();
                blockY = block->pos().y();

                if ((blockLeft <= ballLeft && ballRight <= blockRight) && (blockY == ballBtm)) // top
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case SOUTHEAST:
                        ball->setDirection(NORTHEAST);
                        break;
                    case SOUTHWEST:
                        ball->setDirection(NORTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit top of block"));
                }
                else if ((blockLeft <= ballLeft && ballRight <= blockRight) && (ballY == blockBtm)) // bottom
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(SOUTHEAST);
                        break;
                    case NORTHWEST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit bottom of block"));
                }
                else if ((blockY <= ballY && ballBtm <= blockBtm) && ballRight == blockLeft) // left
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(NORTHWEST);
                        break;
                    case SOUTHEAST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit left side of block"));
                }
                else if ((blockY <= ballY && ballBtm <= blockBtm) && blockRight == ballLeft) // right
                {

                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHWEST:
                        ball->setDirection(NORTHEAST);
                        break;
                    case SOUTHWEST:
                        ball->setDirection(SOUTHEAST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit right side of block"));
                }
                else if ((ballLeft <= blockLeft && blockLeft <= ballRight) && blockY == ballBtm) // top left corner X
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case SOUTHEAST:
                        ball->setDirection(NORTHEAST);
                        break;
                    case SOUTHWEST:
                        ball->setDirection(NORTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit top left corner of block"));
                }
                else if ((ballLeft <= blockLeft && blockLeft <= ballRight) && ballY == blockBtm) // bottom left corner X
                {

                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(SOUTHEAST);
                        break;
                    case NORTHWEST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit bottom left corner of block"));
                }
                else if ((ballLeft <= blockRight && blockRight <= ballRight) && blockY == ballBtm) // top right corner X
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case SOUTHEAST:
                        ball->setDirection(NORTHEAST);
                        break;
                    case SOUTHWEST:
                        ball->setDirection(NORTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit top right corner of block"));
                }
                else if ((ballLeft <= blockRight && blockRight <= ballRight) && ballY == blockBtm) // bottom right corner X
                {

                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(SOUTHEAST);
                        break;
                    case NORTHWEST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit bottom right corner of block"));
                }
                else if ((ballY <= blockY && blockY <= ballBtm) && ballRight == blockLeft) // top left corner Y
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(NORTHWEST);
                        break;
                    case SOUTHEAST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit side of top left corner of block"));
                }
                else if ((ballY <= blockY && blockY <= ballBtm) && blockRight == ballLeft) // top right corner Y
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHWEST:
                        ball->setDirection(NORTHEAST);
                        break;
                    case SOUTHWEST:
                        ball->setDirection(SOUTHEAST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit side of top right corner of block"));

                }
                else if ((ballY <= blockBtm && blockBtm <= ballBtm) && ballRight == blockLeft) // bottom left corner Y
                {
                    paddleDir = ball->getDirection();

                    switch(paddleDir)
                    {
                    case NORTHEAST:
                        ball->setDirection(NORTHWEST);
                        break;
                    case SOUTHEAST:
                        ball->setDirection(SOUTHWEST);
                        break;
                    }

                    delete block;
                    blockHit = true;
                    dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                    emit(eventTriggered("Ball hit side of bottom left corner of block"));
                }
                else if ((ballY <= blockBtm && blockBtm <= ballBtm) && blockRight == ballLeft) // bottom right corner Y
            {
                paddleDir = ball->getDirection();

                switch(paddleDir)
                {
                case NORTHWEST:
                    ball->setDirection(NORTHEAST);
                    break;
                case SOUTHWEST:
                    ball->setDirection(SOUTHEAST);
                    break;
                }

                delete block;
                blockHit = true;
                dynamic_cast<GameScreen*>(this->object->parent())->incScore(250);

                emit(eventTriggered("Ball hit side of bottom right corner of block"));
            }
            }
        }
    }


    windowCopy = dynamic_cast<QMainWindow*>(this->object->parent());
    ballCopy = dynamic_cast<Label*>(windowCopy->findChild<Label*>("ball"));
    Label *paddleCopy = dynamic_cast<Label*>(windowCopy->findChild<Label*>("paddle"));
    paddleLoc = ballCopy->pos();
    paddleDir = ballCopy->getDirection();
    safeX = 300 - ballCopy->width();
    safeY = 500 - ballCopy->height() + windowCopy->menuBar()->height();
    menuBarH = windowCopy->menuBar()->height();

    if (!blockHit)
    {
        switch(paddleDir)
        {
        case NORTHEAST:
            if (paddleLoc.x() + 1 > safeX + 1) ballCopy->setDirection(NORTHWEST);
            else if (paddleLoc.y() - menuBarH < 1) ballCopy->setDirection(SOUTHEAST);
            paddleLoc.setX(paddleLoc.x() + 1);
            paddleLoc.setY(paddleLoc.y() - 1);
            break;
        case EAST:
            if (paddleLoc.x() + 1 > safeX + 1) ballCopy->setDirection(WEST);
            paddleLoc.setX(paddleLoc.x() + 1);
            break;
        case SOUTHEAST:
            if (paddleLoc.x() + 1 > safeX + 1) ballCopy->setDirection(SOUTHWEST);
            else if (paddleLoc.y() + 1 > safeY + 1)
            {
                paddleCopy->deleteLater();
                ballCopy->object->stop();
                ballCopy->object->deleteLater();
                ballCopy->deleteLater();
                emit(lifeLost());
            }
            paddleLoc.setX(paddleLoc.x() + 1);
            paddleLoc.setY(paddleLoc.y() + 1);
            break;
        case SOUTHWEST:
            if (paddleLoc.x() - 1 < 1) ballCopy->setDirection(SOUTHEAST);
            else if (paddleLoc.y() + 1 > safeY + 1)
            {
                paddleCopy->deleteLater();
                ballCopy->object->stop();
                ballCopy->object->deleteLater();
                ballCopy->deleteLater();
                emit(lifeLost());
            }
            paddleLoc.setX(paddleLoc.x() - 1);
            paddleLoc.setY(paddleLoc.y() + 1);
            break;
        case WEST:
            if (paddleLoc.x() - 1 < 1) ballCopy->setDirection(EAST);
            paddleLoc.setX(paddleLoc.x() - 1);
            break;
        case NORTHWEST:
            if (paddleLoc.x() - 1 < 1) ballCopy->setDirection(NORTHEAST);
            else if (paddleLoc.y() - menuBarH < 1) ballCopy->setDirection(SOUTHWEST);
            paddleLoc.setX(paddleLoc.x() - 1);
            paddleLoc.setY(paddleLoc.y() - 1);
        }
    }

    ballCopy->move(paddleLoc.x(), paddleLoc.y());
    blockHit = false;
}

void Timer::writeEvent(QString str)
{
    GameScreen *gs = dynamic_cast<GameScreen*>(this->object->parent());
    gs->appendEventLog(str);
}

void Timer::setActive(bool b)
{
    if (b) this->start();
    else this->stop();
}
