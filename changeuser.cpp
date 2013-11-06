#include "changeuser.h"
#include "ui_changeuser.h"

changeUser::changeUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changeUser)
{
    ui->setupUi(this);
}

changeUser::~changeUser()
{
    delete ui;
}

void changeUser::on_cancelBtn_clicked()
{
    this->hide();
    ui->usernameEdit->clear();
}
