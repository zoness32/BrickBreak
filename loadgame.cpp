#include "loadgame.h"
#include "ui_loadgame.h"

LoadGame::LoadGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadGame)
{
    ui->setupUi(this);
}

LoadGame::~LoadGame()
{
    delete ui;
}
