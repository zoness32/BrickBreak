#include "gamescreen.h"
#include "ui_gamescreen.h"
#include "startup.h"
#include "shape.h"
#include "timer.h"
#include <QStringList>
#include "StringListModel.h"
#include "Label.h"
#include <sstream>

#define PADDLEWIDTH 59
#define PADDLEHEIGHT 12
#define BALLWIDTH 14
#define BALLHEIGHT 14

GameScreen::GameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
    tmp = new QMainWindow(this);
    paddleIcon = new QPixmap("C:/Users/TAYLOR/Documents/C++ Files/BrickBreak/paddle.png");
    ballIcon = new QPixmap("C:/Users/TAYLOR/Documents/C++ Files/BrickBreak/white_ball.png");
    gameOverIcon = new QPixmap("C:/Users/TAYLOR/Documents/C++ Files/BrickBreak/gameover.png");
    gameOverlay = new QPixmap("C:/Users/TAYLOR/Documents/C++ Files/BrickBreak/background.jpg");
    gameWonIcon = new QPixmap("C:/Users/TAYLOR/Documents/C++ Files/BrickBreak/youwin.jpg");
    overlayLbl = new QLabel(this);
    overlayLbl->setPixmap(*gameOverlay);
    overlayLbl->setGeometry(0, ui->menuBar->height(), this->width() - (this->width() - ui->rightLine->pos().x()), this->height() - (this->height() - ui->bottomLine->pos().y()));

    connect(this, SIGNAL(eventTriggered(QString)), this, SLOT(writeEvent(QString)));
    connect(this, SIGNAL(gameEnded()), this, SLOT(gameOver()));

    diff = EASY;
    level = 1;
    newLevel(level);
    createActions();
    createMenus();
    createPaddle();
    createBall();
    numLives = 3;

    time = new Timer(this, "time");
    connect(time, SIGNAL(timeout()), this, SLOT(decrementTimer()));
    cheatModeActive = false;
    spacePressed = false;
    score = 0;
    createBlocks();
    eventLogFullSizePos = new QPoint(310, 10);
    eventLogHalfSizePos = new QPoint(310, 200);
    hideCheatMode();
    setLivesText(numLives);
    setTimeText(timeLeft);
    setLevelText(level);
    setScoreText(score);
}

GameScreen::~GameScreen()
{
    delete ui;
}

void GameScreen::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
}

void GameScreen::returnToMenu()
{
    ball->object->stop();
    paddle->object->stop();
    time->stop();
    menu = new QuitToMainMenu(this);
    menu->show();
}

void GameScreen::quitToMenu()
{
    menu = new QuitToMainMenu(this);
    menu->show();
}

void GameScreen::createActions()
{
    quit = new QAction("Main Menu", this);
    connect(quit, SIGNAL(triggered()), this, SLOT(returnToMenu()));
    save = new QAction("Save and Quit", this);
    connect(save, SIGNAL(triggered()), dynamic_cast<startup*>(this->parent()), SLOT(saveGame()));
}

void GameScreen::createMenus()
{
    ui->menuBar->addAction(quit);
    ui->menuBar->addAction(save);
}

void GameScreen::createBall()
{
    ball = new Label(this, "ball");
    ball->setPixmap(*ballIcon);
    int width = (this->width() - (this->width() - ui->rightLine->pos().x()));
    ball->setGeometry((width / 2) - (BALLWIDTH / 2), paddle->pos().y() - PADDLEHEIGHT, BALLWIDTH, BALLHEIGHT);
    ball->setEnabled(false);
    ball->show();
    Timer *timer = new Timer(ball, "ball");
    ball->object = timer;
    timer->object = ball;
    timer->setInterval(ballSpeed);

    connect(timer, SIGNAL(lifeLost()), this, SLOT(decrementLives()));
    connect(timer, SIGNAL(gameWon()), this, SLOT(gameIsWon()));
    emit(eventTriggered("Ball created"));
}

void GameScreen::createPaddle()
{
    paddle = new Label(this, "paddle");
    paddle->setPixmap(*paddleIcon);
    int width = (this->width() - (this->width() - ui->rightLine->pos().x()));
    paddle->setGeometry((width / 2) - (PADDLEWIDTH / 2), ui->bottomLine->pos().y() - 5, PADDLEWIDTH, PADDLEHEIGHT);
    paddle->setEnabled(false);
    Timer *tmr = new Timer(paddle, "paddle");
    paddle->object = tmr;
    tmr->object = paddle;
    tmr->setInterval(paddleSpeed);
    connect(tmr, SIGNAL(timeout()), tmr, SLOT(shiftPaddle()));
    paddle->show();

    emit(eventTriggered("Paddle created"));
}

void GameScreen::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space && !spacePressed)
    {
        ball->object->start();
        spacePressed = true;
        time->start(1000);
        emit(eventTriggered("Spacebar pressed"));
    }
    else if (event->key() == Qt::Key_Right && !cheatModeActive)
    {
        paddle->setDirection(EAST);
        paddle->object->start();
    }
    else if (event->key() == Qt::Key_Left && !cheatModeActive)
    {
        paddle->setDirection(WEST);
        paddle->object->start();
    }
    else if (event->key() == Qt::Key_C)
    {
        cheatModeActive ? cheatModeActive = false : cheatModeActive = true;
        cheatModeActive ? emit(eventTriggered("Cheat mode activated")) : emit(eventTriggered("Cheat mode deactivated"));
        toggleCheatMode(cheatModeActive);
        this->hasFocus();
    }
}

void GameScreen::toggleCheatMode(bool b)
{
    if (b)
    {
        ui->ballSpeedBtn->show();
        ui->paddleSpeedBtn->show();
        ui->ballSpeedEdit->show();
        ui->paddleSpeedEdit->show();
        ui->ballSpeedLbl->show();
        ui->paddleSpeedLbl->show();
        ui->infoLbl->show();
        pause();
        ui->textEdit->resize(ui->textEdit->width(), ui->bottomLine->pos().y() - eventLogHalfSizePos->y());
        ui->textEdit->move(*eventLogHalfSizePos);
    }
    else
    {
        ui->ballSpeedBtn->hide();
        ui->paddleSpeedBtn->hide();
        ui->ballSpeedEdit->hide();
        ui->paddleSpeedEdit->hide();
        ui->ballSpeedLbl->hide();
        ui->paddleSpeedLbl->hide();
        ui->infoLbl->hide();
        ui->ballSpeedEdit->clear();
        ui->paddleSpeedEdit->clear();
        unpause();
        ui->textEdit->resize(ui->textEdit->width(), ui->bottomLine->pos().y() - ui->menuBar->height() - 15);
        ui->textEdit->move(*eventLogFullSizePos);
    }
}

void GameScreen::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_Left) paddle->object->stop();
}

void GameScreen::createBlocks()
{
    int rowNum, colorNum = 0;
    QPushButton *row[blocksPerRow];

    for (int i = 0; i < rowCount; i++)
    {
        if (i != 0 && i % 2 == 0)
        {
            colorNum++;
            if (colorNum == 4) colorNum = 0;
        }
        rowNum = i;
        createRow(row, blocksPerRow, rowNum, colorNum);
    }
}

void GameScreen::createRow(QPushButton *row[], int numBlocks, int rowNum, int color)
{
    int x, y, height = 23, width = (this->width() - (this->width() - ui->rightLine->pos().x())) / numBlocks;
    QString style = "";

    if (color == BLUE)
    {
        style = "QPushButton { \n color: black; \n background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(51, 194, 255, 50), stop: 1 rgba(30, 142, 217, 150)); \n border-style: outset; \n border-radius: 3px; \n border-width: 1px; \n border-color: #0E5AC4; \n }";
    }
    else if (color == GREEN)
    {
        style = "QPushButton { \n color: black; \n background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(58, 222, 60, 50), stop: 1 rgba(40, 168, 43, 150)); \n border-style: outset; \n border-radius: 3px; \n border-width: 1px; \n border-color: #107D12; \n }";
    }
    else if (color == RED)
    {
        style = "QPushButton { \n color: black; \n background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(255, 115, 115, 50), stop: 1 rgba(227, 39, 39, 150)); \n border-style: outset; \n border-radius: 3px; \n border-width: 1px; \n border-color: #C40202; \n }";
    }
    else if (color == PURPLE)
    {
        style = "QPushButton { \n color: black; \n background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(237, 90, 215, 50), stop: 1 rgba(194, 58, 173, 150)); \n border-style: outset; \n border-radius: 3px; \n border-width: 1px; \n border-color: #962185; \n }";
    }

    for (int i = 0; i < numBlocks; i++)
    {
        QPushButton *button = new QPushButton(this);
        button->setObjectName("block");
        x = (ui->rightLine->pos().x() / numBlocks) * i;
        y = height * rowNum + ui->menuBar->height();
        button->setGeometry(x, y, width, height);
        button->setEnabled(false);
        button->setStyleSheet(style);
        row[i] = button;
        button->show();
    }
}

void GameScreen::writeEvent(QString str)
{
    ui->textEdit->append(str);
}

void GameScreen::pause()
{
    ball->object->stop();
}

void GameScreen::unpause()
{
    if (spacePressed) ball->object->start();
}

void GameScreen::hideCheatMode()
{
    ui->ballSpeedBtn->hide();
    ui->paddleSpeedBtn->hide();
    ui->ballSpeedEdit->hide();
    ui->paddleSpeedEdit->hide();
    ui->ballSpeedLbl->hide();
    ui->paddleSpeedLbl->hide();
    ui->infoLbl->hide();

    ui->ballSpeedEdit->setFocusPolicy(Qt::ClickFocus);
    ui->paddleSpeedEdit->setFocusPolicy(Qt::ClickFocus);

    ui->textEdit->resize(ui->textEdit->width(), ui->bottomLine->pos().y() - ui->menuBar->height() - 15);
    ui->textEdit->move(*eventLogFullSizePos);
}

void GameScreen::on_ballSpeedBtn_clicked()
{
    int newInt = ui->ballSpeedEdit->text().toInt();
    ball->object->setInterval(newInt);
    ui->ballSpeedEdit->clear();
    ui->ballSpeedEdit->clearFocus();
}

void GameScreen::on_paddleSpeedBtn_clicked()
{
    int newInt = ui->paddleSpeedEdit->text().toInt();
    paddle->object->setInterval(newInt);
    ui->paddleSpeedEdit->clear();
    ui->paddleSpeedEdit->clearFocus();
}

void GameScreen::decrementTimer()
{
    timeLeft--;
    int minutes = timeLeft / 60;
    int seconds = timeLeft % 60;

    QString ss;
    ss.append(QString::number(minutes) + ":");
    if (seconds < 10) ss.append("0");
    ss.append(QString::number(seconds));

    ui->timeLbl->setText("Time: " + ss);
}

void GameScreen::gameOver()
{
    gameOverLbl = new QLabel(this);
    gameOverLbl->setPixmap(*gameOverIcon);
    gameOverLbl->resize(218, 211);
    gameOverLbl->move((this->width() / 2) - (gameOverLbl->width() / 2), (this->height() / 2) - (gameOverLbl->height() / 2));
    gameOverLbl->show();

    restart = new QPushButton(this);
    restart->setGeometry(gameOverLbl->pos().x() + 15, gameOverLbl->pos().y() + (gameOverLbl->height() - 32), 75, 23);
    restart->setText("Restart");
    startup *s = dynamic_cast<startup*>(this->parent());
    connect(restart, SIGNAL(clicked()), s, SLOT(restartGame()));
    restart->show();

    returnToMainMenu = new QPushButton(this);
    returnToMainMenu->setGeometry(gameOverLbl->pos().x() + 132, gameOverLbl->pos().y() + (gameOverLbl->height() - 32), 75, 23);
    returnToMainMenu->setText("Quit");
    connect(returnToMainMenu, SIGNAL(clicked()), this, SLOT(quitToMenu()));
    returnToMainMenu->show();
}

void GameScreen::decrementLives()
{
    QString t = ui->livesLbl->text();
    int livesLeft = t.remove(0, t.length() - 2).toInt();
    ui->livesLbl->setText("Lives Left: " + QString::number(--livesLeft));
    time->stop();
    decScore(500);

    if(livesLeft == 0)
    {
        emit(gameEnded());
    }
    else
    {
        createPaddle();
        createBall();
        spacePressed = false;
    }
}

bool GameScreen::getSpacePressed()
{
    return spacePressed;
}

void GameScreen::setEventLog(QString str)
{
    ui->textEdit->setPlainText(str);
}

QString GameScreen::getEventLog()
{
    return ui->textEdit->toPlainText();
}

void GameScreen::setLivesText(int i)
{
    QString str;
    str.append(QString::number(i));
    ui->livesLbl->setText("Lives Left: " + str);
}

void GameScreen::setScoreText(int i)
{
    QString str;
    str.append(QString::number(i));
    ui->scoreLbl->setText("Score: " + str);
}

void GameScreen::setLevelText(int i)
{
    QString str;
    str.append(QString::number(i));
    ui->levelLbl->setText("Level: " + str);
}

void GameScreen::setTimeText(int i)
{
    int minutes = i / 60;
    int seconds = i % 60;

    QString s;
    s.append(QString::number(minutes) + ":");
    if (seconds < 10) s.append("0");
    s.append(QString::number(seconds));

    ui->timeLbl->setText("Time: " + s);
}

void GameScreen::gameIsWon()
{
    ball->object->stop();
    paddle->object->stop();
    time->stop();

    gameWonLbl = new QLabel(this);
    gameWonLbl->setPixmap(*gameWonIcon);
    gameWonLbl->setGeometry(50, 60, 401, 351);
    gameWonLbl->show();

    mainMenuBtn = new QPushButton(this);
    mainMenuBtn->setGeometry(75, 370, 75, 23);
    mainMenuBtn->setText("Main Menu");
    mainMenuBtn->show();
    connect(mainMenuBtn, SIGNAL(clicked()), this, SLOT(quitToMenu()));

    saveAndQuitBtn = new QPushButton(this);
    saveAndQuitBtn->setGeometry(165, 370, 81, 23);
    saveAndQuitBtn->setText("Save and Quit");
    saveAndQuitBtn->show();
    connect(saveAndQuitBtn, SIGNAL(clicked()), this, SLOT(saveAndQuit()));

    restartBtn = new QPushButton(this);
    restartBtn->setGeometry(261, 370, 75, 23);
    restartBtn->setText("Replay");
    restartBtn->show();
    connect(restartBtn, SIGNAL(clicked()), this, SLOT(restartLevel()));

    nextLvlBtn = new QPushButton(this);
    nextLvlBtn->setGeometry(355, 370, 75, 23);
    nextLvlBtn->setText("Next Level >");
    nextLvlBtn->show();
    connect(nextLvlBtn, SIGNAL(clicked()), this, SLOT(nextLevel()));

}

void GameScreen::saveAndQuit()
{
    startup *s = dynamic_cast<startup*>(this->parent());
    s->saveGame();
}

void GameScreen::restartLevel(int i)
{
    if (i == 1) { }
    else
    {
        delete gameWonLbl;
        delete saveAndQuitBtn;
        delete restartBtn;
        delete mainMenuBtn;
        delete nextLvlBtn;
        delete ball;
        delete paddle;

        createBlocks();
        createPaddle();
        createBall();
    }
}

void GameScreen::restartLevel()
{
    delete gameWonLbl;
    delete saveAndQuitBtn;
    delete restartBtn;
    delete mainMenuBtn;
    delete nextLvlBtn;
    delete ball;
    delete paddle;

    spacePressed = false;

    createBlocks();
    createPaddle();
    createBall();
}

void GameScreen::nextLevel()
{
    level++;
    newLevel(level);
}

void GameScreen::appendEventLog(QString str)
{
    ui->textEdit->append(str);
}

void GameScreen::incScore(int i)
{
    score += i;
    setScoreText(score);
}

void GameScreen::decScore(int i)
{
    score -= i;
    setScoreText(score);
}

void GameScreen::newLevel(int newLevel)
{
    timeLeft = 300;
    blocksPerRow = 1;   // level 1 block-per-row count will be 2
    rowCount = 3;

    if (newLevel == 1 && diff == EASY) diff = EASY;
    else if (newLevel == 2 && diff != HARD) diff = MEDIUM;
    else if (newLevel == 3) diff = HARD;

    if (diff == EASY)
    {
        ballSpeed = 10;
        paddleSpeed = 10;
    }
    else if (diff == MEDIUM)
    {
        ballSpeed = 7;
        paddleSpeed = 7;
    }
    else if (diff == HARD)
    {
        ballSpeed = 5;
        paddleSpeed = 5;
    }

    for (int i = 0; i < newLevel; i++)
    {
        blocksPerRow++;
        rowCount++;
    }

    setTimeText(timeLeft);
    setLevelText(newLevel);
    restartLevel(newLevel);
    spacePressed = false;
}

