#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_difficultySlider_sliderMoved(int position)
{
    if (position == 1) ui->difficultyLbl->setText("Difficulty: Easy");
    else if (position == 2) ui->difficultyLbl->setText("Difficulty: Medium");
    else if (position == 3) ui->difficultyLbl->setText("Difficulty: Hard");
}
