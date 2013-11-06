#ifndef CHEATMODE_H
#define CHEATMODE_H

#include <QDialog>

namespace Ui {
    class CheatMode;
}

class CheatMode : public QDialog
{
    Q_OBJECT

public:
    explicit CheatMode(QWidget *parent = 0);
    ~CheatMode();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CheatMode *ui;
};

#endif // CHEATMODE_H
