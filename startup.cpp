#include "startup.h"
#include "ui_startup.h"


startup::startup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startup)
{
    ui->setupUi(this);
    optionsUi = new Options(this);
    helpUi = new help(this);
}

startup::~startup()
{
    delete ui;
}

void startup::on_optionsBtn_clicked()
{
    optionsUi->show();
}

void startup::on_helpBtn_clicked()
{
    helpUi->show();
}

void startup::on_newGameBtn_clicked()
{
    gameScreen = new GameScreen(this);
    gameScreen->show();
    this->hide();
}

void startup::restartGame()
{
    delete gameScreen;
    gameScreen = new GameScreen(this);
    gameScreen->show();
}


void startup::saveGame()
{
    gameScreen->ball->object->stop();
    gameScreen->paddle->object->stop();
    gameScreen->time->stop();
    gameScreen->spacePressed = false;

    QList<QPushButton*> blocks = gameScreen->findChildren<QPushButton*>("block");

    QString filename = QFileDialog::getSaveFileName(this, "Save Form", "", "");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_7); // Change this based on current Qt version

    out << blocks.length();
    for (int i = 0; i < blocks.length(); ++i)
    {
        QPushButton *block = dynamic_cast<QPushButton*>(blocks[i]);
        out << block->styleSheet();
        out << block->geometry();
        out << block->isEnabled();
    }

    out << gameScreen->ball->geometry();
    Timer *tmr = dynamic_cast<Timer*>(gameScreen->ball->object);
    out << tmr->interval();
    out << tmr->isActive();
    out << gameScreen->paddle->geometry();
    tmr = dynamic_cast<Timer*>(gameScreen->paddle->object);
    out << tmr->interval();
    out << tmr->isActive();
    out << gameScreen->numLives;
    out << gameScreen->timeLeft;
    out << gameScreen->score;
    out << gameScreen->level;
    out << gameScreen->getEventLog();
    out << gameScreen->spacePressed;
    delete gameScreen;
    this->show();

    file.close();
}

void startup::loadGame()
{
    int numLives, score, level, timeLeft;
    gameScreen = new GameScreen(this);
    QList<QPushButton*> blocks = this->findChildren<QPushButton*>("block");
    for (int i = 0; i < blocks.count(); i++)
    {
        delete blocks[i];
    }

    QString styleSheet, eventLog;
    QRect geo;
    bool enabled;
    int numBlocks, interval;

    QString filename = QFileDialog::getOpenFileName(this, "Load Form", "", "");
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, tr("Unable to load file"), file.errorString());
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_7);

    in >> numBlocks;
    for (int i = 0; i < numBlocks; i++)
    {
        QPushButton *block = new QPushButton(gameScreen);
        in >> styleSheet;
        in >> geo;
        in >> enabled;
        block->setStyleSheet(styleSheet);
        block->setGeometry(geo);
        block->setEnabled(enabled);
        block->setObjectName("block");
    }

    in >> geo;
    gameScreen->ball->setGeometry(geo);
    in >> interval;
    gameScreen->ball->object->setInterval(interval);
    in >> enabled;
    gameScreen->ball->object->setActive(enabled);

    in >> geo;
    gameScreen->paddle->setGeometry(geo);
    in >> interval;
    gameScreen->paddle->object->setInterval(interval);
    in >> enabled;
    gameScreen->paddle->object->setActive(enabled);

    in >> numLives;
    gameScreen->setLivesText(numLives);
    in >> timeLeft;
    gameScreen->setTimeText(timeLeft);
    in >> score;
    gameScreen->setScoreText(score);
    in >> level;
    gameScreen->setLevelText(level);
    in >> eventLog;
    gameScreen->setEventLog(eventLog);
    in >> gameScreen->spacePressed;
    in >> enabled;

    file.close();

    gameScreen->show();
}

void startup::on_loadGameBtn_clicked()
{
    loadGame();
}

