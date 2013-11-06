#include "quittomainmenu.h"
#include "ui_quittomainmenu.h"
#include "gamescreen.h"
#include "startup.h"

QuitToMainMenu::QuitToMainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuitToMainMenu)
{
    ui->setupUi(this);
}

QuitToMainMenu::~QuitToMainMenu()
{
    delete ui;
}

void QuitToMainMenu::on_buttonBox_accepted()
{
    GameScreen *gs = dynamic_cast<GameScreen*>(this->parent());
    startup *start = dynamic_cast<startup*>(gs->parent());
    delete gs;
    start->show();
}

void QuitToMainMenu::on_buttonBox_rejected()
{
    GameScreen *gs = dynamic_cast<GameScreen*>(this->parent());
    gs->spacePressed = false;
    delete this;
}
