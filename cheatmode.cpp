#include "cheatmode.h"
#include "ui_cheatmode.h"
#include "gamescreen.h"

CheatMode::CheatMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheatMode)
{
    ui->setupUi(this);
    this->setParent(parent);
    //GameScreen gs = (GameScreen)this->parent();
}

CheatMode::~CheatMode()
{
    delete ui;
}

void CheatMode::on_buttonBox_accepted()
{

}

void CheatMode::on_buttonBox_rejected()
{
    //ui->ballSpeedEdit->clear();
    //ui->paddleSpeedEdit->clear();
}
